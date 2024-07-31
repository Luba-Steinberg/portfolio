#include <stddef.h> /*size_t*/

int MissingNumber(int *nums, size_t elems)
{
	size_t i = 0;
	int sum = i, expect_sum = 0;
	
	for (i = 0; i < elems; ++i)
	{
		sum += nums[i];
		expect_sum +=i;
	}
	
	expect_sum += elems;
	return (expect_sum - sum);
}

int main()
{
	int i = 0, miss_num = 74;
	int nums[1024] = {0};
	
	for (i = 0; i < 1024; ++i)
	{
		if (i >= miss_num)
		{
			nums[i] = i + 1; 
			continue;
		}
		
		nums[i] = i;
	}
	
	miss_num = MissingNumber(nums, 1024);
	
	printf("the missing number is %i", miss_num);
	return (0);
}
