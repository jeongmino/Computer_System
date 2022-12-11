#include "../include/L1.hpp"

L1::L1(int size)
{
    this->size_ = size;
    this->set_ = new set[size];
}

L1::~L1()
{
    // delete this->temp_data_;
}