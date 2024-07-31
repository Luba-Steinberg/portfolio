#include <stdio.h>

int PairsSetBits(int num);
void SwapOne(int *num1, int *num2);
void SwapTwo(int *num1, int *num2);
void SwapBitWise(int *num1, int *num2);
int LongSetBits(int num3);
int ShiftBits(int num1);

int main()
{
	int num1 = 3, num2 = 8, num3 = 255;
	int set_pairs = 0;
	int set_bit_long;
	int num1_shift;
	set_pairs = PairsSetBits(num1);
	printf("There are %i pairs of set bits\n", set_pairs);
	SwapOne(&num1, &num2);
	printf("The numbers after swap1 are %i and %i\n", num1, num2);
	SwapTwo(&num1, &num2);
	printf("The numbers after swap2 are %i and %i\n", num1, num2);
	SwapBitWise(&num1, &num2);
	printf("The numbers after swap bitwise are %i and %i\n", num1, num2);
	set_bit_long = LongSetBits(num3);
	printf("There are %i set bits in long %i\n", set_bit_long, num3);
	num1_shift = ShiftBits(num1);
	printf("num1 %i after shift is num %i", num1, num1_shift);
	return (0);
}

int PairsSetBits(int n)
{
	int i = 0, counter = 0;
	for (i = 0; i < 7; ++i)
	{
		if ((n&(1<<i))&&(n&(1<<(i+1))))
		{
			++counter;
		}
	}
	return(counter);
}

void SwapOne(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void SwapTwo(int *num1, int *num2)
{
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

void SwapBitWise(int *num1, int *num2)
{
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}

int LongSetBits(int num3)
{
	int counter = 0;
	while (num3)
	{
		num3 = (num3&(num3-1));
		++counter;
	}
	return (counter);
}

int ShiftBits(int num1)
{
	return(num1>>1);
}


