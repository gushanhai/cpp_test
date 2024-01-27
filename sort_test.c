#include"sort.h"

void Test_time()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	//int* a3 = (int*)malloc(sizeof(int) * N);
	//int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	//int* a6 = (int*)malloc(sizeof(int) * N);
	//int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = N - 1; i >= 0; --i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		//a3[i] = a1[i];
		//a4[i] = a1[i];
		a5[i] = a1[i];
		//a6[i] = a1[i];
		//a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	//printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	//printf("BubbleSort:%d\n", end7 - begin7);

	//printf("SelectSort:%d\n", end3 - begin3);
	//printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	//free(a3);
	//free(a4);
	free(a5);
	//free(a6);
	//free(a7);
}
int main()
{
	int arr[] = { 4,1,3,6,2,5,7,9,8,0 };
	int arr2[] = { 3,1,4,6,7,5,2,9,0,8 };
	int arr3[] = { 1,3,2,5,6,9,8,7,0,4 };

	InsertSort(arr, 10);
	
	//ShellSort(arr, 10);

	PrintArry(arr, sizeof(arr) / sizeof(int));

	//int (*p)() = add;
	//int num = add(3, 4);
	//printf("%d %p %p %p %p\n", num, &num ,add ,add(3,4));
	//printf("%p ",*p);
	//ShellSort(arr, sizeof(arr)/sizeof(int));
	//BubbleSort(arr2, sizeof(arr2) / sizeof(int));
	MergeSortNonR(arr2, sizeof(arr2) / sizeof(int));
	PrintArry(arr2, sizeof(arr2) / sizeof(int));


	//SelectSort(arr3, sizeof(arr3) / sizeof(int));
	//MergeSort(arr3, sizeof(arr3) / sizeof(int));
	//QuickSort(arr3, 0, sizeof(arr3) / sizeof(int) - 1);
	CountSort(arr3, sizeof(arr3) / sizeof(int));
	PrintArry(arr3, sizeof(arr3) / sizeof(int));

	//Test_time();
	return 0;
}