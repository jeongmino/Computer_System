#include "../include/L2.hpp"

L2::L2(int size)
{
    this->size_ = size;
    this->set_ = new set[size];
}

L2::~L2()
{
    // delete this->temp_data_;
}