#include <stdio.h>

int ProfitSearch(int *array, int size, int *min, int *max);

int main()
{
	int array[] = {6, 1, 3, 5, 1, 41, 9, 1};
	int size = 0;
	int ptr_min=0;
	int ptr_max=0;
	
	size = sizeof(array) / sizeof(array[0]);

	ProfitSearch(array, size, &ptr_min, &ptr_max);
	
	return (0);	
}

int ProfitSearch(int *array, int size, int *min, int *max)
{
	int i = 0;
        int local_minInd = 0;
	int profit = 0;
	
	for (i = 0; i<size; ++i)
	{
		if (array[i]>array[local_minInd])
		{
		
			if ((array[i] - array[local_minInd])>profit)
			{
				profit = array[i] - array[local_minInd];
				*max = i;
				*min = local_minInd;
			}
		}
			
		if (array[i] < array[local_minInd])
		{
			local_minInd = i;
		}

	}
	printf("The indexes of the buy and sell are %d and %d\n", *min, *max);
	return (0);
}

