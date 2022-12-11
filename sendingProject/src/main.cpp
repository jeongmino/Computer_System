#include "../include/L1.hpp"
#include "../include/L2.hpp"
#include "../include/L3.hpp"
#include "../include/L4.hpp"


#include <fstream>
#include <string>
#include <sstream>
#include <string>

template<typename L>
void parsing(L& cache, int& i, std::string& str_buf, int max, std::fstream& fs){
    
    int idx = 0;
    
    while(idx < max){
        getline(fs, str_buf,'\n');
        switch (i % 3)
        {
            case 0:
                cache.getSet()[idx].temp_data.date = str_buf;
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

    while(idx < max){
        getline(fs, str_buf,'\n');
        switch (i % 6)
        {
            case 0:
                l3.getLine()[idx][0].temp_data.date = str_buf;
                break;
            case 1:
                l3.getLine()[idx][0].temp_data.hour = stoi(str_buf);
                break;
            case 2:
                l3.getLine()[idx][0].temp_data.temperature = stof(str_buf);
                break;
            case 3:
                l3.getLine()[idx][1].temp_data.date = str_buf;
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
        std::cout << idx << std::endl;
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
    
    parsing(l1, i, str_buf, 1, fs);
    parsing(l2, i, str_buf, 16, fs);
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

    int i = 0;
    insertData(l1, l2, l3, l4);
    for (i = 0; i < 1; i++){
        std::cout << "cnt" << std::endl;
        std::cout << "data : " <<l1.getSet()[i].temp_data.date << '\t'
        << "hour : " << l1.getSet()[i].temp_data.hour << '\t'
        << "temp : " <<l1.getSet()[i].temp_data.temperature << std::endl;
    }
    std::cout << "--------------L2L2L2-----------------" << std::endl;
    for (i = 0; i < 16; i++){
        std::cout << "cnt" << std::endl;
        std::cout << "data : " <<l2.getSet()[i].temp_data.date << '\t'
        << "hour : " << l2.getSet()[i].temp_data.hour << '\t'
        << "temp : " <<l2.getSet()[i].temp_data.temperature << std::endl;
    }
    for (i = 0; i < 256; i++){
        std::cout << "cnt" << std::endl;
        std::cout << "----------- i : " << i << "-----first----------------" << std::endl;
        std::cout << "data : " <<l3.getLine()[i][0].temp_data.date << '\t'
        << "hour : " << l3.getLine()[i][0].temp_data.hour << '\t'
        << "temp : " <<l3.getLine()[i][0].temp_data.temperature << std::endl;
        std::cout << "cnt" << std::endl;
        std::cout << "----------- i : " << i << "-----second----------------" << std::endl;
        std::cout << "data : " <<l3.getLine()[i][1].temp_data.date << '\t'
        << "hour : " << l3.getLine()[i][1].temp_data.hour << '\t'
        << "temp : " <<l3.getLine()[i][1].temp_data.temperature << std::endl;
    }
     std::cout << "--------------&&&&&&&&&&&&&-----------------" << std::endl;
     for (i = 0; i < 4096; i++){
        std::cout << "cnt" << std::endl;
        std::cout << "data : " <<l4.getSet()[i].temp_data.date << '\t'
        << "hour : " << l4.getSet()[i].temp_data.hour << '\t'
        << "temp : " <<l4.getSet()[i].temp_data.temperature << std::endl;
    }

    return 0;
}
