#include "../include/L4.hpp"

L4::L4(int size)
{
    this->size_ = size;
    this->set_ = new set[size];
}

L4::~L4()
{
    // delete this->temp_data_;
}