#include "../include/L4.hpp"

L4::L4(int size)
{
    this->size_ = size;
    this->set_ = new set[size];
    this->hit_ = 0;
    this->miss_ = 0;
    this->acTime_ = 100;
    this->hitRatio_ = 0;
    for (int i = 0; i < size; i++) {
        this->set_[i].tag = i;
        this->set_[i].vaild_data = 1;
    }
}

L4::~L4()
{
    // delete this->temp_data_;
}