#include <stdio.h> /*for printf*/
#include <stdlib.h> /*for calloc*/
#include "bitwise.h"

#define BITS 8 

int main()
{
	Pow2Test();
	IsPowerOfTwoLoopTest();
	IsPowerOfTwoNoLoopTest();
	AddOneTest();
	ThreeBitsNumbersTest();
	ByteMirrorTest();
	ByteMirrorNoLoopTest();
	FindSecondSixthBitTest();
	DevidedBySixteenTest();
	SwapNumsBitWiseTest();
	SetBitsCountTest();
	SetBitsNoLoopCountTest();
	FloatSetBitsTest();
	
	return (0);
}

int Pow2Test()
{
	unsigned int x = 3, y = 4;
	unsigned int result;
	result = Pow2(x, y);
	printf("%d", result);
	return (0);
}

unsigned long Pow2(unsigned int x, unsigned int y)
{
	
	return ((unsigned long)x<<(unsigned long)y);
}

int IsPowerOfTwoLoopTest()
{
	unsigned int n = 128;
	IsPowerOfTwoLoop(n);
	return(0);
}

int IsPowerOfTwoLoop(unsigned int n)
{
	int i = 0, counter = 0;
	
	for (i = 0; i<BITS*4; ++i)
	{
		if (n&1)
		{
			++counter;
		}
		n = n>>1;
		if (counter>1)
		{
			return (0);
		}
	}
	if (1 == counter)
	{
		return (1);
	}
	return(0);
}

int IsPowerOfTwoNoLoopTest()
{
	unsigned int n;
	int result;
	n = 64;
	result = IsPowerOfTwoNoLoop(n);
	if (0 == result)
	{
		printf("The number is power of 2\n");
	}
	else 
	{
		printf ("The number is not power of 2\n");
	}
	return (0);
}
int IsPowerOfTwoNoLoop(unsigned int n)
{
	return (n && ((n & (n-1)) == 0 ));
}

int AddOne(unsigned int num)
{
	int i = 0;
	while (num&(1<<i))
	{
		num = num^(1<<i);
		++i;
	}
		num = num | (1<<i);
	return num;
}

int AddOneTest()
{
	unsigned int num = 71, result = 0;
	result = AddOne(num);
	printf("The new number is %d\n", result);
	return (0);
}

int ThreeBitsNumbers(unsigned int *array, size_t size)
{
	size_t i = 0, j = 0;
	int counter = 0;

	for (i = 0; i<size; ++i)
	{
		counter = 0;
		for (j = 0; j < BITS*4; ++j)
		{
			if (array[i] & (1<<j))
			{
				++counter;
			}
		}	
		if (3 == counter)
		{
			printf("%d has 3 bits on\n", array[i]);
		} 
	}
	return (0);
}
int ThreeBitsNumbersTest()
{
	unsigned int array[] = {1, 100, 89, 650, 1000};
	size_t size;
	size = sizeof(array) / array[0];
	ThreeBitsNumbers(array, size);
	return (0);
}

char ByteMirror(unsigned char num)
{
	int i = 0;
	for (i = 0; i < 4; ++i)
	{
		if ((num&(1<<i))^(num&(1<<(BITS-1-i))))
		{
			num = num ^ (1<<i);
			num = num ^ (1<<(BITS-1-i));
		}
	}
	printf("The mirrored number is %d\n", num);
	return (num);
}

int ByteMirrorTest()
{
	unsigned char num = 8;

	ByteMirror(num);
	return (0);
}

char ByteMirrorNoLoop(unsigned char num)
{
	num = (num & 0xF0) >> 4 | (num & 0x0F) << 4;
   	num = (num & 0xCC) >> 2 | (num & 0x33) << 2;
	num = (num & 0xAA) >> 1 | (num & 0x55) << 1;
	printf("ByteMirrorNoLoop num is %d\n", num);
	return (num);
}

int ByteMirrorNoLoopTest()
{
	unsigned int num = 8;
	num = ByteMirrorNoLoop(num);
	printf("The mirrored num is %d\n", num);
	return (0);
}

unsigned char SwapBit(unsigned char num)
{
	return((num&(1<<2))<<2|(num&1<<4)>>2|(num&(~20)));
}

int FindSecondORSixthBit(unsigned char num)
{
	return((num&(1<<1))||(num&(1<<5)));
}

int FindSecondSixthBit(unsigned char num)
{
	return((num&(1<<1))&&(num&(1<<5)));
}

int FindSecondSixthBitTest()
{
	unsigned char num = 0;
	int result = 0;
	int result2 = 0;
	num = 56;
	result = FindSecondSixthBit(num);
	printf("result %d\n", result);
	result2 = FindSecondORSixthBit(num);
	printf("result2 %d\n", result2 );
	SwapBit(num);
	return (0);
}

int DevidedBySixteen(unsigned int num)
{
	num = num>>4;
	num = num<<4;
	return (num);
}

int DevidedBySixteenTest()
{
	unsigned int num = 0, result = 0;
	num = 81;
	result = DevidedBySixteen(num);
	printf("The closest number devided by 16 is %d\n", result);
	return (0);	
}

int SwapNumsBitWise(unsigned int *num1, unsigned int *num2)
{
	*num2 = *num2^*num1;
	*num1 = *num2^*num1;
	*num2 = *num2^*num1;
	return(0);
}

int SwapNumsBitWiseTest()
{
	unsigned int num1 = 0, num2 = 0;
	num1 = 103;
	num2 = 57;
	SwapNumsBitWise(&num1, &num2);
	printf("The numbers are %d and %d\n", num1, num2);
	return(0);
}

int SetBitsCount(int num)
{	
	size_t i = 0;
	int counter = 0;

	for (i = 0; i < BITS*4; ++i)
		{
			if (num&(1<<i))
			{
				++counter;
			}
		}	
	return (counter);
}

int SetBitsCountTest()
{
	int num = 0, result = 0;
	
	num = 255;
	result = SetBitsCount(num);
	printf("There are %d set bits in number %d\n", result, num);
	return (0);
}

int SetBitsNoLoopCount(int num)
{
	num = (num & 0x55555555) + ((num>>1) & 0x55555555);
	num = (num & 0x33333333) + ((num>>2) & 0x33333333);
	num = (num & 0x0f0f0f0f) + ((num>>4) & 0x0f0f0f0f);
	num = (num & 0x00ff00ff) + ((num>>8) & 0x00ff00ff);
	num = (num & 0x0000ffff) + ((num>>16) & 0x0000ffff);
	
	return (num);
}

int SetBitsNoLoopCountTest()
{
	int num = 0, temp = 0, result = 0;
	
	num = 38;
	temp = num;
	result = SetBitsNoLoopCount(num);
	printf("With no loop there are %d set bits in number %d\n", result, temp);
	return (0);
}

int FloatSetBits(void *num_ptr)
{
	unsigned int *ptr = NULL; 
	int i = 0; 
	unsigned int temp = 0; 
	
	ptr = (unsigned int *)num_ptr;
	for (i = 31; i > 0; --i)
	{
		temp = !!(*ptr & (1<<(i)));	
		printf("%d ", temp);
	}
	return(0);
}

int FloatSetBitsTest()
{
	float num = 3.44;
	printf("hi");
	FloatSetBits(&num);
	return (0);
}
