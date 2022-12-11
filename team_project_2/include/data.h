#ifndef DATA_H
# define DATA_H

#include <iostream>

typedef struct{
    std::string date;
    int hour;
    float temperature;
    int data_tag;
} temp_data;


typedef struct{
    int vaild_data;
    int tag;
    temp_data temp_data;
} set;

#endif 