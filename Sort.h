//
// Created by 76947 on 2018/3/6.
//

#ifndef PRACTICE_CLION_SORT_H
#define PRACTICE_CLION_SORT_H

#include <iostream>
using namespace std;
void swap1(int *left, int *right);
void swap2(int &left, int &right);
void swap3(int &left, int &right);
// 直接插入排序
void InsertSort(int a[], int n);

// 希尔排序
void ShellInsertSort(int n, int a[], int dl);

void ShellSort(int a[], int n);

void ShellSort2(int *arr, int N);

// 桶排序
void TongSort(int a[], int n);

// 冒泡排序
void BubbleSort(int a[], int n);

// 快速排序
void quickSort(int a[], int left, int right);

// 堆排序
void percDown(int *arr, int i, int N);

void HeapSort(int *arr, int N);

// 简单选择排序
void SelectSort(int arr[], int num);

//归并排序
bool MergeSort(int a[], int n);

#endif //PRACTICE_CLION_SORT_H
