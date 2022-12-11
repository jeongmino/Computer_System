#ifndef CACHE_ALGORITHM
# define CACHE_ALGORITHM

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <time.h>
#include "L1.hpp"
#include "L2.hpp"
#include "L3.hpp"
#include "L4.hpp"

int callData(int tag_idx, L1& l1, L2& l2, L3& l3 ,L4& l4);

void dataTest(L1& l1, L2& l2, L3& l3 ,L4& l4);

int findL1(L1& cache, int size, int tag_idx, int& data_idx);

int findL2(L2& cache, int size, int tag_idx, int& data_idx);

int findL3(L3& cache, int size, int tag_idx, int& data_idx, int& data_jdx);

int findL4(L4& cache, int size, int tag_idx, int& data_idx);

void fetchL1FromL2(L1& l1, L2& l2, int data_idx);

void fetchL2FromL3(L1& l1, L2& l2, L3& l3, int data_idx, int data_jdx);

void fetchL3FromL4(L1& l1, L2& l2, L3& l3, L4& l4, int data_idx);

void makeRandomData(void);
#endif