#include <stddef.h> /*size_t*/
#include <stdio.h> /*printf*/

long *SumIntPairsToLongs(int arr[], size_t numOfElements);

long *SumIntPairsToLongs(int arr[], size_t numOfElements)
{
	size_t i = 0, j = 0;
	
	for (i = 0, j = 0; j < numOfElements; ++i, j+=2)
	{
		arr[i] = arr[j] + arr[j+1];
		arr[j] = 0;
		arr[j + 1] = 0;
	}
	
	printf("new size is %lu", i);
	return ((long *)arr);
}

int main()
{

	int arr[20];
	long arrOfLonSums[20];
	int i = 0;

	for (i = 0; i < 20; ++i)
	{
		arr[i] = i;
	}
	
	SumIntPairsToLongs(arr, 20);
	
	for (i = 0; i < 10; ++i)
	{
		printf("arr on index %i is %li", i, arr[i]);
	}
	
	return (0);
}
