#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void InsertSort(int* arr,int n);//直接插入

void ShellSort(int* arr, int n);//希尔

void PrintArry(int* arr, int n);

void BubbleSort(int* arr, int n);//优化冒泡

void SelectSort(int* arr, int n);//选择排序

void QuickSort(int* arr, int start, int end);//含小区间优化及三数取中

void MergeSort(int* arr, int n);//递归版归并

void MergeSortNonR(int* arr, int n);//非递归版归并

void CountSort(int* arr, int n);//相对映射的计数排序