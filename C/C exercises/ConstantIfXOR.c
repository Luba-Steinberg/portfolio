#include <stddef.h>/*size_t*/
#include <stdio.h>/*printf*/

int IsNumberPresent(int arr[], size_t size, int num)
{
	int i = 0, result = 0;
	
	for (i = 0; i < size; ++i)
	{
		result += !!(num^arr[i]);
	}
	
	
	
	return (!(size==result));
	
}

int main ()
{
	int arr[15];
	size_t i = 0;
	int num = 16;
	int status =0;
	for (i = 0; i < 15; ++i)
	{
		arr[i] = i*i;
	}
	
	status = IsNumberPresent(arr, i+1, num);
	
	printf("the result is %i", status);
	
	return (0);
}
