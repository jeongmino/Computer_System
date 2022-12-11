#include "../include/L1.hpp"
#include "../include/L2.hpp"
#include "../include/L3.hpp"
#include "../include/L4.hpp"
#include "../include/cache_algorithm.h"

#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include <algorithm>

int Cache::call_num_ = 0;
float Cache::total_hit_ratio_ = 0;

int callData(int tag_idx, L1& l1, L2& l2, L3& l3 ,L4& l4){

    int data_idx = 0;
    int data_jdx = 0;
    int check = findL1(l1, 1, tag_idx ,data_idx);
    if (check == tag_idx){
        l1.setHit(l1.getHit() + 1);
        // std::cout << "l1 : hit " << std::endl;
        // std::cout << "data idx : " << data_idx << std::endl;
        return l1.getAcTime();
    }
    l1.setMiss(l1.getMiss() + 1);
    ///////////////////////////////////////////////////
    check = findL2(l2, 16, tag_idx ,data_idx);
    if (check == tag_idx){
        l2.setHit(l2.getHit() + 1);
        // std::cout << "l2 : hit " << std::endl;
        // std::cout << "data idx : " << data_idx << std::endl;
        fetchL1FromL2(l1, l2, data_idx);
        return l1.getAcTime() + l2.getAcTime();
    }
    l2.setMiss(l2.getMiss() + 1);
    ///////////////////////////////////////////////////
    check = findL3(l3, 256, tag_idx ,data_idx, data_jdx);
    if (check == tag_idx){
        l3.setHit(l3.getHit() + 1);
        // std::cout << "l3 : hit " << std::endl;
        // std::cout << "data idx : " << data_idx << std::endl;
        // std::cout << "data jjjjjjjjjjjjjjjjjjjjdx : " << data_jdx << std::endl;
        fetchL2FromL3(l1, l2, l3, data_idx, data_jdx);
        return l1.getAcTime() + l2.getAcTime() + l3.getAcTime();
    }
    l3.setMiss(l3.getMiss() + 1);
    //////////////////////////////////////////////////
    check = findL4(l4, 4096, tag_idx ,data_idx);
    if (check == tag_idx){
        l4.setHit(l4.getHit() + 1);
        // std::cout << "l4 : hit " << std::endl;
        // std::cout << "data idx : " << data_idx << std::endl;
        fetchL3FromL4(l1, l2, l3, l4, data_idx);
        return l1.getAcTime() + l2.getAcTime() + l4.getAcTime();
    }
    // std::cout << "No Data here" << std::endl;
    return -1;
}


void insertData(set* array){
    std::string str_buf;         
    std::fstream fs; 
    int i = 0;
    int idx = 0;
    fs.open("temperature.data",std::ios::in);
    
    while(idx < 4369){
        getline(fs, str_buf,'\n');
        switch (i % 3)
        {
            case 0:
                array[idx].temp_data.date = str_buf;
                break;
            case 1:
                array[idx].temp_data.hour = stoi(str_buf);
                break;
            case 2:
                array[idx].temp_data.temperature = stof(str_buf);
                idx++;
                break;
        }
        i++;
        // if ( i == 17482)
            // break;
        // std::cout<< i << std::endl;
        // std::cout << str_buf << std::endl;
    }
}

template<typename L>
void parsing(L& cache, int& i, std::string& str_buf, int max, std::fstream& fs){
    
    int idx = 0;
    //512
    while(idx < max){
        getline(fs, str_buf,'\n');
        switch (i % 3)
        {
            case 0:
                cache.getSet()[idx].temp_data.date = str_buf;
                cache.getSet()[idx].temp_data.data_tag = idx + 512;
                break;
            case 1:
                cache.getSet()[idx].temp_data.hour = stoi(str_buf);
                break;
            case 2:
                cache.getSet()[idx].temp_data.temperature = stof(str_buf);
                idx++;
                break;
        }
        i++;
        // if ( i == 17482)
            // break;
        // std::cout<< i << std::endl;
        // std::cout << str_buf << std::endl;
    }
}

void L3_parsing(L3& l3, int& i, std::string& str_buf, int max, std::fstream& fs){
    
    int idx = 0;
    int tag_idx = 0;
    while(idx < max){
        getline(fs, str_buf,'\n');
        switch (i % 6)
        {
            case 0:
                l3.getLine()[idx][0].temp_data.date = str_buf;
                l3.getLine()[idx][0].temp_data.data_tag = tag_idx++;
                break;
            case 1:
                l3.getLine()[idx][0].temp_data.hour = stoi(str_buf);
                break;
            case 2:
                l3.getLine()[idx][0].temp_data.temperature = stof(str_buf);
                break;
            case 3:
                l3.getLine()[idx][1].temp_data.date = str_buf;
                l3.getLine()[idx][1].temp_data.data_tag = tag_idx++;
                break;
            case 4:
                l3.getLine()[idx][1].temp_data.hour = stoi(str_buf);
                break;
            case 5:
                l3.getLine()[idx][1].temp_data.temperature = stof(str_buf);
                idx++;
                break;
        }
        i++;
        // std::cout << idx << std::endl;
        // std::cout << i << std::endl;
        // if ( i == 17482)
            // break;
        // std::cout<< i << std::endl;
        // std::cout << str_buf << std::endl;
    }
}

void insertData(L1& l1, L2& l2, L3& l3 ,L4& l4)
{
    // inFile.close();
    std::string str_buf;         
    std::fstream fs; 
    int i = 0;
    int idx = 0;
    fs.open("temperature.data",std::ios::in);
    
    // parsing(l1, i, str_buf, 1, fs);
    // parsing(l2, i, str_buf, 16, fs);
    L3_parsing(l3, i,str_buf, 256, fs);
    parsing(l4, i, str_buf, 4096, fs);
    fs.close();
    return ;
}

int main(void)
{
    L1 l1(1);
    L2 l2(16);
    L3 l3(256);
    L4 l4(4096);
    set* oneArray = new set[4369]; //1 + 16 + 256 + 4096

    int i = 0;
    makeRandomData();
    insertData(l1, l2, l3, l4);
    insertData(oneArray);
    // for (i = 0; i < 1; i++){
    //     std::cout << "cnt" << std::endl;
    //     std::cout << "data : " <<l1.getSet()[i].temp_data.date << '\t'
    //     << "hour : " << l1.getSet()[i].temp_data.hour << '\t'
    //     << "temp : " <<l1.getSet()[i].temp_data.temperature << std::endl;
    // }
    // std::cout << "--------------L2L2L2-----------------" << std::endl;
    // for (i = 0; i < 16; i++){
    //     std::cout << "cnt" << std::endl;
    //     std::cout << "data : " <<l2.getSet()[i].temp_data.date << '\t'
    //     << "hour : " << l2.getSet()[i].temp_data.hour << '\t'
    //     << "temp : " <<l2.getSet()[i].temp_data.temperature << std::endl;
    // }
    // for (i = 0; i < 256; i++){
    //     std::cout << "cnt" << std::endl;
    //     std::cout << "----------- i : " << i << "-----first----------------" << std::endl;
    //     std::cout << "data : " <<l3.getLine()[i][0].temp_data.date << '\t'
    //     << "hour : " << l3.getLine()[i][0].temp_data.hour << '\t'
    //     << "temp : " <<l3.getLine()[i][0].temp_data.temperature << std::endl;
    //     std::cout << "cnt" << std::endl;
    //     std::cout << "----------- i : " << i << "-----second----------------" << std::endl;
    //     std::cout << "data : " <<l3.getLine()[i][1].temp_data.date << '\t'
    //     << "hour : " << l3.getLine()[i][1].temp_data.hour << '\t'
    //     << "temp : " <<l3.getLine()[i][1].temp_data.temperature << std::endl;
    // }
    //  std::cout << "--------------&&&&&&&&&&&&&-----------------" << std::endl;
    //  for (i = 0; i < 4096; i++){
    //     std::cout << "cnt" << std::endl;
    //     std::cout << "data : " <<l4.getSet()[i].temp_data.date << '\t'
    //     << "hour : " << l4.getSet()[i].temp_data.hour << '\t'
    //     << "temp : " <<l4.getSet()[i].temp_data.temperature << std::endl;
    //     std::cout << "tag_data : " << l4.getSet()[i].temp_data.data_tag << std::endl;
    // }
    // for (int j = 0; j < 4369; j++) {
    //     std::cout << oneArray[j].temp_data.date << '\t'
    //     << oneArray[j].temp_data.hour << '\t'
    //     << oneArray[j].temp_data.temperature << std::endl;
    // }
    int time = 0;

    // time = callData(5, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(100, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(250, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(400, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(511, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(512, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(1234, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(2222, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(4123, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(51111, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;

    //////////////////////////////////////////////////////////
    // time = callData(2222, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(1222, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(2222, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(1222, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    // time = callData(1222, l1, l2, l3, l4);
    // std::cout << "time : " << time << std::endl;
    ////////////////////////////////////////////////////////
    dataTest(l1, l2, l3, l4);
    delete[] oneArray;
    return 0;
}
