#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int SwapFunc(int *num1_ptr, int *num2_ptr);
int SwapFuncTest();
char CopyArrays(char *str, char *str_2, int str_len);
char CopyArraysTest();
int PrintAddress();
size_t SwapSizeT (size_t *first_ptr, size_t *second_ptr);
size_t SwapSizetTest();
size_t SwapSizetPointers();
int SwapSizetPointersTest();

int SwapFunc(int *num1_ptr, int *num2_ptr){
	int temp = 0;
	
	temp = *num1_ptr;
	*num1_ptr = *num2_ptr;
	*num2_ptr = temp;
		
	printf("The swapped numbers in subfunc are %d and %d \n", *num1_ptr, *num2_ptr);
	
	return 0;	
}

int SwapFuncTest()
{
	int num1 = 0;
	int num2 = 0;

	printf("Enter a number");
	scanf("%d", &num1); 
	
	printf("Enter another number");
	scanf("%d", &num2); 
		
	SwapFunc(&num1, &num2);
	
	printf("The swapped numbers in main are %d and %d \n", num1, num2);
	
	return 0;
}

char CopyArrays(char *str, char *str_2, int str_len)
{
		int i = 0;
		str_2 = (char*)malloc(str_len*(sizeof(char)));
		
		assert(str_2 != NULL);
	 
	 	for (i = 0; i < str_len; ++i)
	 	{
	 		str_2[i] = str[i];
	 	}
	 	
	 	printf("The copied array in copy is %s \n", str_2);
	 	
}

char CopyArraysTest()
{
	char str[]={"Hello, it's me"};
	char *str_2;
	int str_len = strlen(str);
	
	printf("The original array is %s \n", str);	
	
	CopyArrays(str, str_2,  str_len);
	 
	return 0;
}

int PrintAddress()
{
	static int s_i = 7;
	int i = 7; 
	int *ptr = &i;
	int *ptr2 = (int*)malloc(sizeof(int));
	
	printf("The address of i is %p \n", &i);
	printf("The address of i is %p \n", &s_i);
	printf("The address of ptr, pointer to i, is %p \n", &ptr);
	printf("The address of ptr2, malloced pointer, is %p \n", &ptr2);
	
	if (ptr)
	{
	 	int **ptr3 = &ptr;
	 	printf("The address of ptr,  pointer that is created if prt exists, is %p \n", &ptr3);
	}

	free(ptr2);
	  
	printf("The pointer ptr2 is now freed and its address is %p \n", &ptr2);
	
}

size_t SwapSizeT (size_t *first_ptr, size_t *second_ptr)
{
	size_t temp;
	temp = *first_ptr;
	*first_ptr = *second_ptr;
	*second_ptr = temp;
}

size_t SwapSizetTest()
{
	size_t first = 4000;
	size_t second = 6000;
	
	printf("First number is %zu, second number is %zu", first, second);
	
	SwapSizeT (&first, &second); 
	
	printf("After swapping first number is %zu, second number is %zu", first, second);
	
	return 0;
}

size_t SwapSizetPointers(size_t *first_ptr, size_t *second_ptr)
{
	size_t temp = *first_ptr;
	
	*first_ptr = *second_ptr;
	*second_ptr = temp;
	
	printf("After swapping pointers in SwapSizet function first number is %zu, second number is %zu", *first_ptr, *second_ptr);

}

int SwapSizetPointersTest()
{
	size_t first = 4000;
	size_t second = 6000;
	size_t * ptr1 = &first;
	size_t * ptr2 = &second;
	printf("First number is %zu, second number is %zu", first, second);
	
	SwapSizetPointers(ptr1, ptr2); 
	
	printf("After swapping pointers in main first number is %zu, second number is %zu", first, second);
	
	return 0;

}

int main()
{
	SwapFuncTest();
	CopyArraysTest();
	PrintAddress();
	SwapSizetTest ();
	SwapSizetPointersTest();
	
	return 0;
}

