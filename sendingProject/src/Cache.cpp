
#include "../include/Cache.hpp"

Cache::Cache(void) : size_(0), set_(0)
{
    std::cout << "Cache instructor is called " << std::endl;
}

Cache::Cache(int size) : size_(size)
{
    this->set_ = new set[size];
    std::cout << "Cache instructor is called " << std::endl;
}

int Cache::getSize(void) const
{
    return this->size_;
}

// temp_data* Cache::getTempData(void)
// {
//     return this->temp_data_;
// }

set* Cache::getSet(void)
{
    return this->set_;
}

Cache::~Cache(void)
{
    // delete[] temp_data_;
    std::cout << "Cache destructor is called " << std::endl;
}