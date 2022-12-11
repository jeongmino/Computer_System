#include "../include/L1.hpp"

L1::L1(int size)
{
    this->size_ = size;
    this->set_ = new set[size];
    this->hit_ = 0;
    this->miss_ = 0;
    this->acTime_ = 1;
    this->hitRatio_ = 0;
    for (int i = 0; i < size; i++) {
        this->set_[i].tag = 0;
        this->set_[i].vaild_data = 0;
        this->set_[i].temp_data.data_tag = 0;
    }
}

L1::~L1()
{
    // delete this->temp_data_;
}