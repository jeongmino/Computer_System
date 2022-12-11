#include "../include/cache_algorithm.h"

void fetchL1FromL2(L1& l1, L2& l2, int data_idx)
{
    l1.setSet(l2.getSet(), data_idx, 0);
    // std::cout << "f1~2 : success" << std::endl;
}

void fetchL2FromL3(L1& l1, L2& l2, L3& l3, int data_idx, int data_jdx)
{
    for (int i = l2.getSize() - 1; i > 0; i--){
        l2.setSet(l2.getSet(), i - 1, i);
    }
    l2.setSet(l3.getLine()[data_idx], data_jdx, 0);
    // std::cout << "f2~3: success" << std::endl;
    fetchL1FromL2(l1, l2, 0);
}

void fetchL3FromL4(L1& l1, L2& l2, L3& l3, L4& l4, int data_idx)
{
    l3.setLine(l3.getLine(), l3.getSize() - 1, 0, l3.getSize() - 1, 1);
    for (int i = l3.getSize() - 2; i >= 0; i--){
        for (int j = 0; j < 2; j++){
            l3.setLine(l3.getLine(), i, 1, i + 1, 0);
            l3.setLine(l3.getLine(), i, 0, i, 1);
        }
    }
    l3.getLine()[0][0].tag = l4.getSet()[data_idx].tag;
    l3.getLine()[0][0].vaild_data = l4.getSet()[data_idx].vaild_data;
    l3.getLine()[0][0].temp_data.data_tag = l4.getSet()[data_idx].temp_data.data_tag;
    l3.getLine()[0][0].temp_data.date = l4.getSet()[data_idx].temp_data.date;
    l3.getLine()[0][0].temp_data.hour = l4.getSet()[data_idx].temp_data.hour;
    l3.getLine()[0][0].temp_data.temperature = l4.getSet()[data_idx].temp_data.temperature;
    // std::cout << "f3~4: success" << std::endl;
    fetchL2FromL3(l1, l2, l3, 0, 0);
}