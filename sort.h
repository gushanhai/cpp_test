#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void InsertSort(int* arr,int n);//ֱ�Ӳ���

void ShellSort(int* arr, int n);//ϣ��

void PrintArry(int* arr, int n);

void BubbleSort(int* arr, int n);//�Ż�ð��

void SelectSort(int* arr, int n);//ѡ������

void QuickSort(int* arr, int start, int end);//��С�����Ż�������ȡ��

void MergeSort(int* arr, int n);//�ݹ��鲢

void MergeSortNonR(int* arr, int n);//�ǵݹ��鲢

void CountSort(int* arr, int n);//���ӳ��ļ�������