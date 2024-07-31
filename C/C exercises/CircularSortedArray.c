#include <stddef.h> /*size_t*/

int FindIndex(int *arr, size_t size, int num)
{
	size_t low = 0, mid = 0, high = 0;

	high = size - 1;
	mid = ((high - low) / 2) + low;
	
	while (low != high)
	{
		if (num == arr[mid])
		{	
			return (mid);
		}
		if (arr[mid -1] > low) /*the first part is sorted*/
		{
			if (num <= arr[mid - 1] && num >= arr[low])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		else
		{
			if (num >= arr[mid + 1] && num <= arr[high])
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		mid = (high - low) / 2 + low;
	}
	
	return (-1);
}

int main()
{
	int arr[] = {7, 8, 11, 1, 4, 5};
	size_t index = -2;
	
	index = FindIndex(arr, 6, 1);
	printf("requested num is on index %li", index);
	return (0);
}
