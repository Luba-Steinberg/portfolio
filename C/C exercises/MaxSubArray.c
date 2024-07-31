#include <stdio.h>
#include <stddef.h>

int MaxSubArray(int *arr, size_t arr_size, size_t *start_arr, size_t *end_arr);

int main() 
{

	size_t arr_size = 0;
	int arr[9] = {-2, 1, -3, 4, -1, 2, 3, -5, 4};
	size_t start_arr = 0, end_arr = 0;
	long int final_num_sum = 0;
	
	arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("The size is %lu\n", arr_size);
	
	final_num_sum =MaxSubArray(arr, arr_size, &start_arr, &end_arr);
	printf("The max sum is %li\n", final_num_sum);
	printf("The indexes are %lu and %lu\n", start_arr, end_arr);
	
	return (0);
}

int MaxSubArray(int *arr, size_t arr_size, size_t *start_arr, size_t *end_arr)
{
	int i = 0;
	long int sum = 0, max_sum = 0;
	size_t arr_start = 0, arr_end = 0;
	
	while (i < arr_size)
	{
		sum = 0;
		arr_start = i;
		sum = arr[i];
		
		while(sum > 0 && i < arr_size)
		{
			if (sum > max_sum)
			{
				max_sum = sum;
				arr_end = i;
			}
			
			++i;
			sum += arr[i];
		}
		++i;
		
	} 
	
	*start_arr = arr_start;
	*end_arr = arr_end;
	
	return (max_sum);
	
	
}
