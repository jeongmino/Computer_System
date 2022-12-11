
#include "../include/cache_algorithm.h"

int findL1(L1& cache, int size, int tag_idx, int& data_idx){
    cache.setAcNum(cache.getAcNum() + 1);
    for (int i = 0; i < size; i++){
        if (cache.getSet()[i].temp_data.data_tag == tag_idx && cache.getSet()[i].vaild_data == 1){
            data_idx = i;
            return tag_idx;
        }   
    }
    return -1;
}

int findL2(L2& cache, int size, int tag_idx, int& data_idx){
    cache.setAcNum(cache.getAcNum() + 1);
    for (int i = 0; i < size; i++){
        if (cache.getSet()[i].temp_data.data_tag == tag_idx && cache.getSet()[i].vaild_data == 1){
            data_idx = i;
            return tag_idx;
        }
    }
    return -1;
}


int findL4(L4& cache, int size, int tag_idx, int& data_idx){
    cache.setAcNum(cache.getAcNum() + 1);
    for (int i = 0; i < size; i++){
        if (cache.getSet()[i].temp_data.data_tag == tag_idx && cache.getSet()[i].vaild_data == 1){
            data_idx = i;
            return tag_idx;
        }
    }
    return -1;
}


int findL3(L3& cache, int size, int tag_idx, int& data_idx, int& data_jdx){
    cache.setAcNum(cache.getAcNum() + 1);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 2; j++){
            if (cache.getLine()[i][j].temp_data.data_tag == tag_idx &&
                cache.getLine()[i][j].vaild_data == 1){
                data_idx = i;
                data_jdx = j;
                return tag_idx;
            }
        }
    }
    return -1;
}