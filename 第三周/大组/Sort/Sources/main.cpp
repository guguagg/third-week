#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"sort.h"

#define N 10000



int main()
{
	int max = 0;
	while (1)
	{
		system("cls");
		clock_t start = clock();
		int choice = 0;
		int a[N] = { 0 };
		int temp[N] = { 0 };

		srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			a[i] = rand() % 10000;
		}

		printf("原数组：\n");
		for (int i = 0; i < N; i++)
		{
			if (i % 15 == 0 && i != 0)
				printf("\n");
			printf("%-4d   ", a[i]);
		}
		printf("\n");
		printf("1、插入排序\n2、归并排序\n3、快速排序（递归版）\n4、计数排序\n5、基数计数排序\n0、退出\n");
		scanf("%d", &choice);
		while (getchar() != '\n');
		switch (choice)
		{
		case 1://插入排序
			InsertSort(a, N);
			break;

		case 2://归并排序
			MergeSort(a, 0, N-1, temp);
			break;

		case 3://快速排序（递归版）
			QuickSort_Recursion(a, 0, N-1);
			break;

		case 4://计数排序
			max = Max(a);
			CountSort(a, N, max);
			break;

		case 5://基数计数排序
			RadixCountSort(a, N);
			break;

		case 0://退出
			return 0;
		default:
			break;
		}

		printf("排序后数组：\n");
		for (int i = 0; i < N; i++)
		{
			if (i % 15 == 0 && i != 0)
				printf("\n");
			printf("%-4d   ", a[i]);
		}
		printf("\n");
		clock_t diff = clock() - start;
		printf("共计耗时 %d ms\n", diff);
		system("pause");

	}
	return 0;
}