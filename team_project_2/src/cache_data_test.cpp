#include "../include/cache_algorithm.h"

void dataTest(L1& l1, L2& l2, L3& l3 ,L4& l4)
{
    std::string str_buf;         
    std::fstream fs; 
    int i = 0;
    int tag = 0;
    fs.open("./randomDir/random.txt",std::ios::in);
    
    while (i < 5000)
    {
        getline(fs, str_buf, ',');
        tag = stoi(str_buf);
        callData(tag, l1, l2, l3, l4);
        i++;
        Cache::call_num_++;
    }
    Cache::total_hit_ratio_ = (static_cast<float>(l1.getHit() + l2.getHit() + l3.getHit()) / static_cast<float>(Cache::call_num_)) * 100;
    l1.setHitRatio(l1.getHitRatio() + (static_cast<float>(l1.getHit()) / static_cast<float>(l1.getAcNum())));
    l2.setHitRatio(l2.getHitRatio() + (static_cast<float>(l2.getHit()) / static_cast<float>(l2.getAcNum())));
    l3.setHitRatio(l3.getHitRatio() + (static_cast<float>(l3.getHit()) / static_cast<float>(l3.getAcNum())));
    l4.setHitRatio(l4.getHitRatio() + (static_cast<float>(l4.getHit()) / static_cast<float>(l4.getAcNum()))); 
    std::cout << "l1 hit ratio : " << l1.getHitRatio() * 100 << "%" << std::endl;
    std::cout << "l2 hit ratio : " << l2.getHitRatio() * 100 << "%" << std::endl;
    std::cout << "l3 hit ratio : " << l3.getHitRatio() * 100 << "%" << std::endl;
    std::cout << "l4 hit ratio : " << l4.getHitRatio() * 100 << "%" << std::endl;
    std::cout << "total hit ratio : " << roundf(Cache::total_hit_ratio_) << "%" << std::endl;
    float avgMemoryAccessTime = l1.getAcTime() * l1.getHitRatio()+ 
    (1 - l1.getHitRatio()) * (l2.getAcTime() * l2.getHitRatio() + 
    (1 - l2.getHitRatio()) *(l3.getAcTime() * l3.getHitRatio() +
    (1 - l3.getHitRatio()) *(l4.getAcTime() * l4.getHitRatio())));
    std::cout << "avg memory access time : " << avgMemoryAccessTime << std::endl;


    // std::cout << "l1 access : " << static_cast<float>(l1.getAcNum() ) * 100<< std::endl;
    // std::cout << "l2 access : " << static_cast<float>(l2.getAcNum() ) * 100<< std::endl;
    // std::cout << "l3 access : " << static_cast<float>(l3.getAcNum() ) * 100<< std::endl;
    // std::cout << "l4 access : " << static_cast<float>(l4.getAcNum() ) * 100<< std::endl;
    fs.close();
}