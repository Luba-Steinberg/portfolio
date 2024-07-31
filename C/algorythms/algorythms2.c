#include <stddef.h> /*size_t*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*calloc*/
#include <time.h> /*time_t*/

#define SIZE (5000)
#define MAX2(num1, max) (num1 > max ? num1 : max)
#define MIN2(num, min) (num < min ? num : min)

static int GetDigit(int num, int ten_power);

int *CountingSort(int *input_array, size_t size)
{
	int max = 0, min = 0;
	size_t i = 0;
	int *count_arr = NULL, *output_arr = NULL;

	
	for (i = 0; i < size; ++i)
	{
		if (input_array[i] > max) 
		{
			max = input_array[i]; 
		}
	}
	
	min = max; 
	printf("max is %i\n", max);
	
	for (i = 0; i < size; ++i)
	{
		if (input_array[i] < min) 
		{
			min = input_array[i]; 
		}
	}
	
	printf("min is %i\n", min);
	
	count_arr = (int *)calloc(max + 1  - min, sizeof(int));
	
	for (i = 0; i < size; ++i)
	{
		++count_arr[input_array[i] - min]; 
	}
	
	for (i = 1; i < (size_t)(max + 1 - min); ++i)
	{
		count_arr[i] = count_arr[i - 1] + count_arr[i];

	}
	
	output_arr = (int *)malloc(size* sizeof(int));
	
	for (i = size - 1; (int)i >= 0 ; --i)
	{
		output_arr[count_arr[input_array[i] - min] - 1] = input_array[i];
		-- (count_arr[input_array[i] - min]);
	}
	
	return(output_arr);
}

int *RadixSort(int *orig_input_array, size_t size)
{
	size_t i = 0, j = 0;
	int max = 0, min = 9, digit_count = 0, power = 1;
	int *input_array = NULL, *count_arr = NULL, *output_arr = NULL;
	
	input_array = (int *)malloc(size*sizeof(int));
	input_array = orig_input_array;
	
	for (i = 0; i < size; ++i)
	{
		max = MAX2(input_array[i], max);
	}
	
	printf("max num is %i\n", max);
	
	while (0 != max)
	{
		max /= 10;
		++ digit_count;
		printf("digit count is %i\n", digit_count);
	}
	
	for (i = 1; (int)i <= digit_count; ++i)
	{
		max = 0;
		min = 9;
		power *= 10;
		
		for (j = 0; j < size; ++j)
		{
			max = MAX2(GetDigit(input_array[j], power), max);
			/*printf("the num on place %i is %i\n", j, input_array[j]);*/
		}
		printf("max is %i\n", max);
		
		for (j = 0; j < size; ++j)
		{
			min = MIN2(GetDigit(input_array[j], power), min);
		}
		printf("min is %i\n", min);
		
		count_arr = (int *)calloc(max + 1 - min, sizeof(int));
		
		for (j = 0; j < size; ++j)
		{
			++count_arr[GetDigit(input_array[j], power) - min];
		}
		
		for (j = 1; j < (size_t)(max + 1 - min); ++j)
		{
			count_arr[j] = count_arr[j - 1] + count_arr[j];
		}
		
		output_arr = (int *)malloc(size * sizeof(int));
		
		for (j = size - 1; (int)j >= 0 ; --j)
		{
			output_arr[count_arr[GetDigit(input_array[j], power) - min] - 1] = input_array[j];
			-- (count_arr[GetDigit(input_array[j], power) - min]);
		}
		
		input_array = output_arr;
	}
	
	return(input_array);
}

static int GetDigit(int num, int ten_power)
{
	printf("the digit is %i", (num % ten_power) / (ten_power / 10));
	return ((num % ten_power) / (ten_power / 10));
}

int main()
{
	int input_array[SIZE];
	int *output_array = NULL;
	clock_t start_t, end_t;
	int i = 0;
	
	output_array = (int *)malloc(sizeof(int)*SIZE);
	
	for (i = 0; i < SIZE; ++i)
	{
		input_array[i] = (rand() % (100)) + 1;
		printf("before sorting with count sort, num on place %d is %d\n", i, input_array[i]);
	}
	
	start_t = clock();
	output_array = CountingSort(input_array, SIZE);
  	printf("Starting of the count sorting, start_t = %ld\n", start_t);
  	end_t = clock();
	printf("End of the count sorting, end_t = %ld\n", end_t);
	
	for (i = 0; i < SIZE; ++i)
	{
		printf("output array after count sorting at place %lu is %i\n", i, output_array[i]);
	}
	
	
	start_t = clock();
	output_array = RadixSort(input_array, SIZE);
  	printf("Starting of the radix sorting, start_t = %ld\n", start_t);
  	end_t = clock();
	printf("End of the radix sorting, end_t = %ld\n", end_t);
	
	for (i = 0; i < SIZE; ++i)
	{
		printf("output array after radix sorting at place %i is %i\n", i, output_array[i]);
	}
	
	return (0);
}
