#include "../include/L2.hpp"

L2::L2(int size)
{
    this->size_ = size;
    this->set_ = new set[size];
    this->hit_ = 0;
    this->miss_ = 0;
    this->acTime_ = 7;
    this->hitRatio_ = 0;
    for (int i = 0; i < size; i++) {
        this->set_[i].tag = 0;
        this->set_[i].vaild_data = 0;
        this->set_[i].temp_data.data_tag = 0;
    }
    
}

L2::~L2()
{
    // delete this->temp_data_;
}