#define _CRT_SECURE_NO_WARNINGS 

#include<stdlib.h>
#include<string.h>

#define N 10000


//插入排序
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int end = i;
		int temp = a[end];
		while (end > 0)
		{
			if (a[end - 1] > temp)
			{
				a[end] = a[end - 1];
				end--;
			}
			else
				break;
		}
		a[end] = temp;
	}

}


//归并排序
void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end)
		return;

	int middle = (begin + end) / 2;
	int begin1 = begin;
	int end1 = middle;
	int begin2 = middle + 1;
	int end2 = end;
	MergeSort(a, begin1, end1, temp);
	MergeSort(a, begin2, end2, temp);

	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			temp[i++] = a[begin1++];
		else
			temp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		temp[i++] = a[begin1++];
	while (begin2 <= end2)
		temp[i++] = a[begin2++];
	memcpy(a + begin, temp + begin, sizeof(int) * (end - begin + 1));
	
}



void swap(int* a, int low, int high) //交换两个数的值
{
	int t = a[low];
	a[low] = a[high];
	a[high] = t;
}


int partition(int* a, int low, int high)  
{
	int point = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= point)
		{
			high--;
		}
		swap(a, low, high);
		while (low < high && a[low] <= point)
		{
			low++;
		}
		swap(a, low, high);
	}
	return low;
}


//快速排序（递归版）
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin < end) 
	{
		int point = partition(a, begin, end);
		QuickSort_Recursion(a, begin, point - 1);
		QuickSort_Recursion(a, point + 1, end);
	}
}


//数组最大值
int Max(int* a)
{
	int max = a[0];
	for (int i = 0; i < 10; i++)
		if (max < a[i])
			max = a[i];
	return max;
}


//计数排序
void CountSort(int* a, int size, int max)
{
	int j = 0;
	int range = max + 1;
	//int* arr = (int*)malloc(sizeof(int) * range);
	int arr[N] = { 0 };
	for (int i = 0; i < range; i++)
		arr[i] = 0;

	for (int i = 0; i < size; i++)
		arr[a[i]]++;

	for(int i = 0;i<range;i++)
		while (arr[i]--)
		{
			a[j] = i;
			j++;
		}
	//free(arr);
}


//基数计数排序
void RadixCountSort(int* a, int size)
{
	int max = Max(a);
	int exp = 1;
	//int* count = (int*)malloc(sizeof(int) * 10);
	//int* output = (int*)malloc(sizeof(int) * size);

	int count[N] = { 0 };
	int output[N] = { 0 };

	while (max / exp > 0)
	{
		for (int i = 0; i < size; i++)
		{
			count[i] = 0;
		}

		for (int i = 0; i < size; i++)
		{
			count[(a[i] / exp) % 10]++;
		}

		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}

		for (int i = size - 1; i >= 0; i--)
		{
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}
		for (int i = 0; i < size; i++)
		{
			a[i] = output[i];
		}
		exp *= 10;
	}

	//free(count);
	//free(output);
}


