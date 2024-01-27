#include"sort.h"

void Swap(int* a1, int* a2)
{
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

void InsertSort(int* arr, int n)//插入排序
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
				arr[end + 1] = arr[end];
			else
				break;
			end--;
		}
		arr[end + 1] = tmp;
	}
}

void ShellSort(int* arr, int n)//希尔排序
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)//多组并排
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}

void PrintArry(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void BubbleSort(int* arr, int n)//冒泡排序（优化版本）
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break; 
	}
}

void SelectSort(int* arr, int n)//选择排序
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int max = start;
		int min = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		Swap(&arr[min], &arr[start]);
		if (max == start)
			max = min;
		Swap(&arr[max], &arr[end]);
		end--;
		start++;
	}
}

int GetMidi(int* a, int left, int right)//三数取中 
{
	int mid = (left + right) / 2;
	// left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])  // mid是最大值
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right]) // mid是最小
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

int PartSort(int* arr,int left,int right)//hoare法：
{
	int mid = GetMidi(arr, left, right);
	Swap(&arr[mid], &arr[left]);

	int key = left;
	while (left < right)
	{
		while (left<right && arr[right]>arr[key])
			right--;
		while (left < right && arr[left] < arr[key])
			left++;
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[left], &arr[key]);
	return left;
}

int PartSort2(int* arr, int left, int right)//蹲坑法:
{
	int mid = GetMidi(arr, left, right);
	Swap(&arr[left], &arr[mid]);

	int key = arr[left];
	int kenwei = left;
	while (left < right)
	{
		while (left<right && arr[right] >= key)
		{
			right--;
		}
		arr[kenwei] = arr[right];
		kenwei = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[kenwei] = arr[left];
		kenwei = left;
	}
	arr[kenwei] = key;
	return left;
}

int PartSort3(int* arr, int left, int right)//前后指针法：
{
	int mid = GetMidi(arr, left, right);
	Swap(&arr[left], &arr[mid]);

	int per = left;
	int cur = left + 1;
	int key = left;
	while (cur <=right)
	{
		if (arr[cur] < arr[key]&&++per!=cur)
		{
			Swap(&arr[cur], &arr[per]);
		}
		++cur;
	}
	Swap(&arr[key], &arr[per]);
	return per;
}

void QuickSort(int* arr, int start, int end)//快排
{
	if (start >= end)
	{
		return;
	}
	int key = PartSort(arr, start, end);
	QuickSort(arr, start, key - 1);	
	QuickSort(arr, key + 1, end);
} 


void _MergeSort(int* arr, int* tmp, int start, int end)//归并排序
{
	if (start >= end)
		return;
	int mid = (end + start) / 2;
	_MergeSort(arr, tmp, start, mid);
	_MergeSort(arr, tmp, mid + 1, end);
	
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	int index = start;
	while (start1 <= end1 && start2 <= end2)
	{
		if (arr[start1] < arr[start2])
			tmp[index++] = arr[start1++];
		else
			tmp[index++] = arr[start2++];
	}
	while (start1 <= end1)
		tmp[index++] = arr[start1++];
	while (start2 <= end2)
		tmp[index++] = arr[start2++];
	memcpy(arr + start, tmp + start, (end - start + 1) * sizeof(int));
}

void MergeSort(int* arr ,int n)//递归版归并
{
	int* tmp = (int*)malloc(n * 4);
	_MergeSort(arr, tmp, 0, n - 1);
	free(tmp);
}

void MergeSortNonR(int* arr, int n)//非递归版归并
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("tmp malloc fail");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int start1 = i, end1 = i + gap - 1;
			int start2 = i + gap, end2 = i + 2 * gap - 1;
			if (start2 >= n)
			{
				break;
			}

			if (end2 >= n)
				end2 = n - 1;
			int index = i;
			while (start1 <= end1 && start2 <= end2)
			{
				if (arr[start1] < arr[start2])
				{
					tmp[index++] = arr[start1++];
				}
				else
					tmp[index++] = arr[start2++];
			}
			while (start1 <= end1)
			{
				tmp[index++] = arr[start1++];
			}
			while (start2 <= end2)
			{
				tmp[index++] = arr[start2++];
			}
			memcpy(arr + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* arr, int n)
{
	int max = arr[0], min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int* tmp = (int*)malloc(sizeof(int) * (max - min + 1));
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	memset(tmp, 0, (max - min + 1) * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		tmp[arr[i] - min]++;
	}

	for (int i = 0; i <= max - min; i++)
	{
		if (tmp[i] != 0)
		{
			arr[i] = i + min;
		}
	}
}