#include <assert.h> /*chech the array */
#include <stddef.h> /*define NULL*/
#include <stdio.h> /*for printf*/
int IsSumFound(int *array, int sum, int *index_a, int *index_b, size_t size);

int main() 
{
	int array[] = {10, 22, 35, 48, 55, 69, 71, 99};
	int sum = 170;
	int index_a = -1, index_b = -1;
	int flag = 0;
	int size;
	size = sizeof(array) / sizeof(array[0]);

	flag = IsSumFound(array, sum, &index_a, &index_b, size);
	printf("%i", flag);
	if (1 == flag)
	{
		printf("The sum is found, and the indexes are %i and %i", index_a, index_b);
	}
	else
	{
		printf("The sum wasn't found");	
	}
	return (0);	
}

int IsSumFound(int *array, int sum, int *index_a, int *index_b, size_t size)
{
	size_t i = 0, j = 0;
	int found_sum = 0, flag = 0;
	
	assert(NULL != array);
	
	j = size - 1;

	while (j>i)
	{
		found_sum = array[i] + array[j];
		if(found_sum < sum)
		{
			++i;
		}
		else 
		if(found_sum > sum)
		{
			--j;
		}
		else
		if (sum == found_sum)
		{
			flag = 1;
			*index_a = i;
			*index_b = j;
			break;
		}
	}
	return flag;
}
