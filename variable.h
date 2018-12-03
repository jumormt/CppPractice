//
// Created by 76947 on 2017/12/5.
//

#ifndef PRACTICE_CLION_VARIABLE_H
#define PRACTICE_CLION_VARIABLE_H

#include <iostream>
#include "ManManager.h"
#include "string.h"
#include <queue>

using namespace std;

// 探究多维数组
void multiDArray();

int (*func(int(&a)[10]))[10];

int stuff_info();

void UseRawMemory();

// 使用vector更新queue;
template <typename T>
void initQueue(vector<T> &vec, queue<T> &que);

#endif //PRACTICE_CLION_VARIABLE_H
