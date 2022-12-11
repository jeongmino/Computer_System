#include "../include/L3.hpp"

L3::L3(int size)
{
    this->size_ = size;
    this->line_ = new set*[size];
    for (int i = 0; i < size; i++){
        this->line_[i] = new set[2];
    }
    this->hit_ = 0;
    this->miss_ = 0;
    this->acTime_ = 20;
    this->hitRatio_ = 0;
    for (int i = 0; i < size; i++){
        this->line_[i][0].tag = i;
        this->line_[i][1].tag = i + 1;
        this->line_[i][0].vaild_data = 1;
        this->line_[i][1].vaild_data = 1;
    }
}

set** L3::getLine(void){
    return this->line_;
}

void L3::setLine(set** line, int f_i, int f_j, int t_i, int t_j){
    this->line_[t_i][t_j].tag = line_[f_i][f_j].tag;
    this->line_[t_i][t_j].vaild_data = line_[f_i][f_j].vaild_data;
    this->line_[t_i][t_j].temp_data.data_tag = line_[f_i][f_j].temp_data.data_tag;
    this->line_[t_i][t_j].temp_data.date = line_[f_i][f_j].temp_data.date;
    this->line_[t_i][t_j].temp_data.hour = line_[f_i][f_j].temp_data.hour;
    this->line_[t_i][t_j].temp_data.temperature = line_[f_i][f_j].temp_data.temperature;
}

L3::~L3()
{
    // delete this->temp_data_;
}