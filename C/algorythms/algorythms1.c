#include <stddef.h> /*size_t*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <time.h> /*time_t*/
 
#define TRUE (1)
#define FALSE (0) 

static void SwapInts(int *num1, int *num2)
{
	int temp = 0;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void BubbleSort(int *grades, size_t size)
{
	size_t i = 0, j = 0;
	int temp = 0;
	int flag = TRUE;
	
	while (TRUE == flag)
	{
		flag = FALSE;
		for (j = 0; j < size - 1; ++j)
		{
			if (grades[j] > grades[j + 1])
			{
				flag = TRUE;
				SwapInts(grades + j, grades + j + 1);
			}
		}
	}
}

void SelectionSort(int *grades, size_t size)
{
	int min = 0, temp = 0;
	size_t i = 0, j = 0, min_index = 0;
	
	for (i = 0; i < size; ++i)
	{
		min = grades[i];
		min_index = i;
		
		for (j = i + 1; j < size; ++j)
		{
			if (grades[j] < min)
			{
				min = grades[j];
				min_index = j;
			}
		}
		
		temp = grades[i];
		grades[i] = min;
		grades[min_index] = temp;	
	}
}

void InsertionSort(int *grades, size_t size)
{
	size_t i = 0, j = 0;
	int temp;
	
	for(i = 1; i < size; ++i)
	{
		j = i;
		while (0 < j && grades[j] < grades[j - 1])
		{
			SwapInts(grades + j, grades + j - 1);
			--j;
		}
	}
}

int cmpfunc(const void *num1, const void *num2) 
{
   return ( *(int*)num1 - *(int*)num2);
}

int main()
{
	int grades[5];
	int i = 0;
	clock_t start_t, end_t;
   	double total_t1;

	printf("/******************Bubble Selection Test***********************/\n");
	for (i = 0; i < 5; ++i)
	{
		grades[i] = (rand() % (100)) + 1;
		printf("before sorting with bubble, num on place %d is %d\n", i, grades[i]);
	}
	
	start_t = clock();
  	printf("Starting of the bubble sorting, start_t = %ld\n", start_t);
	BubbleSort(grades, 5);
	end_t = clock();
	printf("End of the bubble sorting, end_t = %ld\n", end_t);

	for (i = 0; i < 5; ++i)
	{
		printf("after sorting with bubble, num on place %d is %d\n", i, grades[i]);
	}
	
	printf("/******************Sorting Selection Test***********************/\n");
	for (i = 0; i < 5; ++i)
	{
		grades[i] = (rand() % (100)) + 1;
		printf("before sorting with selection, num on place %d is %d\n", i, grades[i]);
	}
	start_t = clock();
  	printf("Starting of the bubble sorting, start_t = %ld\n", start_t);
	SelectionSort(grades, 5);
	end_t = clock();
	printf("End of the bubble sorting, end_t = %ld\n", end_t);
	
	for (i = 0; i < 5; ++i)
	{
		printf("after sorting with selection, num on place %d is %d\n", i, grades[i]);
	}
	
	printf("/******************Sorting Selection Test***********************/\n");
	for (i = 0; i < 5; ++i)
	{
		
		grades[i] = (rand() % (100)) + 1;
		printf("before sorting with insertion, num on place %d is %d\n", i, grades[i]);
	}
		
	InsertionSort(grades, 5);
	
	for (i = 0; i < 5; ++i)
	{
		printf("after sorting with insertion, num on place %d is %d\n", i, grades[i]);
	}
	
	printf("/******************QSORT Test***********************/\n");
	for (i = 0; i < 5; ++i)
	{
		grades[i] = (rand() % (100)) + 1;
		printf("before sorting with qsort, num on place %d is %d\n", i, grades[i]);
	}
	start_t = clock();
  	printf("Starting of the qsort, start_t = %ld\n", start_t);
	qsort(grades, 5, sizeof(int), cmpfunc);
	end_t = clock();
	printf("End of qsort, end_t = %ld\n", end_t);
	for (i = 0; i < 5; ++i)
	{
		printf("after sorting with qsort, num on place %d is %d\n", i, grades[i]);
	}
	
	return (0);
}
