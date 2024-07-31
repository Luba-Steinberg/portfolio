#include <stdio.h>/*printf*/
#include <assert.h>/*assert*/

int i;
char c;
static long int num1;
int Strcmp(const char *str1, const char *str2);
void SwapPtrs(int **a, int **b);
static int FibonacciFunc(int num);

unsigned char MirrorByte(unsigned char byte_num)
{
	unsigned char result = 0;
	int i = 0;
	printf("mirror function number is %d\n", byte_num);
	
	for(i = 0; i < 8; ++i)
	{
		result = result << 1;
		result = result | (byte_num & 1);
		printf("result after push left %d", result);
		byte_num = byte_num >> 1;
	}

	printf("mirror function result is %d\n", result);
	return (result);
}

void MirrorTest()
{
	unsigned char byte_num = 5;
	char byte_char = 127;
	unsigned char mirror_result = 0;
	char mirror_char_result = 0;
	
	mirror_result = MirrorByte(byte_num);
	printf("mirror function result is %d", mirror_result);
}

void UninitialTest()
{
	static int num_stat;
	int num_local;
printf("global int i is %d\n", i);
	printf("global char c is %c\n", c);
	printf("global long int num1 is %d\n", num1);
	printf("global int num_stat is %d\n", num_stat);
	num_stat ++;
	printf("global int num_stat after 1 added is now  %d\n", num_stat);
	printf("non-static local num_stat is %d", num_local);
}

void FlipBitTest()
{
	int num = 10;
	int i = 3;
	
	num = num ^ (1 << i);
	printf("the new num is %d", num);
}

int Strcmp(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);
	
	while('\0' != *str1 && '\0' != *str2)
	{
		++str1;
		++str2;
	}
	
	return (str1- str2);
}

void StrcmpTest()
{
	char *str1 = "Hello, you";
	char *str2 = "Hello, me";
	int result = 0;
	
	result = Strcmp(str1, str2);
	printf("the result of comparison is %d", result);

}

static int FlipDigits(int num)
{
	int flag = 0, result = 0;
	
	if (0 > num)
	{
		flag = 1;
		num = -num;
		printf("the flag is %i", flag);
	} 
	
	
	while (0 != num)
	{
		result = result*10 + num % 10;
		num = (num - num % 10) / 10; 
	}
	
	return (flag ? (-result) : result);
}

void FlipDigitsInNumTest()
{
	int num = -5768;
	num = FlipDigits(num);
	printf("after flip the number is %i", num);
}

void GetBitTest()
{
	int num = 64, bit = 0;
	 
	bit = num & (1 << 7);
	if (bit)
	{
	printf("the bit on place 7 is on", bit);
	}
	else 
	{
		printf("the bit on place 7 is off", bit);
	}
}

void SwapPtrs(int **a, int **b)
{
	int *temp_ptr = NULL;

	printf("a before swap is %i, b before swap is %i\n", **a, **b);
	temp_ptr = *a;
	*a = *b;
	*b = temp_ptr;
	printf("a after swap is %i, b after swap is %i\n", **a, **b);
}
void SwapPtrsTest()
{
	int a = 1, b = 2;
	int *ptr1, *ptr2;
	ptr1 = &a;
	ptr2 = &b;

	printf("a before swap is %i, b before swap is %i\n", a, b);
	printf("a before swap is %i, b before swap is %i\n", *ptr1, *ptr2);
	SwapPtrs(&ptr1, &ptr2);
	printf("a after swap is %i, b after swap is %i\n", *ptr1, *ptr2);
}

int FibonacciFunc(int num)
{
	int elem1 = 0, elem2 = 1, elem_curr = 0, i = 0;
	for (i = 2; i <= num; ++i)
	{
		elem_curr = elem1 + elem2;
		elem1 = elem2;
		elem2 = elem_curr;
	}
	return (elem_curr);
}


void FionacciTest()
{
	int num = 10, result = 0;
	result = FibonacciFunc(num);
	printf("the num on index %i is %i", num, result);
}

int main()
{
	MirrorTest();
	UninitialTest();
	FlipBitTest();
	StrcmpTest();
	FlipDigitsInNumTest();
	GetBitTest();
	SwapPtrsTest();
	FionacciTest();
	
	return (0);
}
