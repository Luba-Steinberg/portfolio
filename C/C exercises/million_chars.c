#include <stdio.h>/*printf*/
#include <stddef.h>/*size_t*/
#include <stdlib.h>/*calloc*/

static size_t zero_counter = 0;
static char *LUT;
void CountSymbols(char symbol);
int CountSetBits(size_t num);

void CountSymbols(char symbol)
{
	int i = 0;
	int max = 0;
	char max_char;
	int symbol_int = 0;
	
	symbol_int = (int)symbol;
	++LUT[symbol_int];
	if ('0' == symbol)
	{
		for(i = 0; i < 256; ++i)
		{
			if (max < LUT[i])
			{
				max  = LUT[i];
				max_char = (char)i;
			}
		}
		printf("the symbol presed the most number of times is %c", max_char);
	}
		
}

int CountSetBits(size_t num)
{
	int counter = 0;
	
	while (num)
	{
		++counter;
		num = num & (num-1);
	}

	return (counter);
}

int main()
{
	int i = 0;
	char symbol;
	size_t num = 25500000;
	int count_bits = 0;
	
	LUT = (char *)calloc(256, sizeof(char));	
	
	count_bits = CountSetBits(num);
	printf("There are %i set bits", count_bits);
	
	CountSymbols('a');
	CountSymbols('a');
	CountSymbols('a');
	CountSymbols('a');
	CountSymbols('a');
	CountSymbols('a');
	CountSymbols('a');
	CountSymbols('8');
	CountSymbols('8');
	CountSymbols('8');
	CountSymbols('8');
	CountSymbols('8');
	CountSymbols('0');
	
	free(LUT);
	LUT = NULL;
	return (0);
}

