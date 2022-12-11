#include "../include/L3.hpp"

L3::L3(int size)
{
    this->size_ = size;
    this->line_ = new set*[size];
    for (int i = 0; i < size; i++){
        this->line_[i] = new set[2];
    }
}

set** L3::getLine(void){
    return this->line_;
}

L3::~L3()
{
    // delete this->temp_data_;
}