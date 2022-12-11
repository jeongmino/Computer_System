
#include "../include/Cache.hpp"

Cache::Cache(void) : size_(0), set_(0)
{
    // std::cout << "Cache instructor is called " << std::endl;
}

Cache::Cache(int size) : size_(size)
{
    this->hit_ = 0;
    this->miss_ = 0;
    this->set_ = new set[size];
    // std::cout << "Cache instructor is called " << std::endl;
}

int Cache::getSize(void) const
{
    return this->size_;
}

int Cache::getHit(void) const
{
    return this->hit_;
}

int Cache::getMiss(void) const
{
    return this->miss_;
}

int Cache::getAcTime(void) const
{
    return this->acTime_;
}

float Cache::getHitRatio(void) const
{
    return this->hitRatio_;
}

int Cache::getAcNum(void) const
{
    return this->acNum_;
}

void Cache::setSet(set* set, int from, int to){
    this->set_[to].tag = set[from].tag;
    this->set_[to].vaild_data = set[from].vaild_data;
    this->set_[to].temp_data.data_tag = set[from].temp_data.data_tag;
    this->set_[to].temp_data.date = set[from].temp_data.date;
    this->set_[to].temp_data.hour = set[from].temp_data.hour;
    this->set_[to].temp_data.temperature = set[from].temp_data.temperature;
}


void Cache::setHit(int hit)
{
    this->hit_ = hit;
}

void Cache::setMiss(int miss)
{
    this->miss_ = miss;
}

void Cache::setAcTime(int acTime)
{
    this->acTime_ = acTime;
}
// temp_data* Cache::getTempData(void)
// {
//     return this->temp_data_;
// }
void Cache::setAcNum(int acNum)
{
    this->acNum_ = acNum;
}

void Cache::setHitRatio(float hit_ratio)
{
    this->hitRatio_ = hit_ratio;
}

set* Cache::getSet(void)
{
    return this->set_;
}

Cache::~Cache(void)
{
    // delete[] temp_data_;
    // std::cout << "Cache destructor is called " << std::endl;
}