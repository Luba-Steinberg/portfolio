#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h> /*0 - tolower in reverse*/
#include <stdlib.h>

void TF(int num);
void TFTest();

void StringReverse(char *start);
void StringReverseTest();


int main()
{
	TFTest();
	StringReverseTest();
	char src[5] = "HeLLo";
	StringReverse(src);
	printf("%s", src);
} 

void TF(int num)
{
	int i = 0;
	for (i = 1; i<num; ++i)
	{
		if (i%3 == 0 && i%5 == 0)
		{
			printf("TF");
		}
			else
			if (i%5 == 0)
			{
			 printf("F");
			}
				else 
				if (i%3 == 0)
				{
					printf("T");
				}
					else
					{
						printf("%i", i);
					}
	} 
}

void TFTest()
{
	int num = 6;
	TF(num);
}
 
void StringReverse(char *start)
{
	char *end = NULL;
	int len = strlen(start);
	char temp = '0';
	assert( NULL != start);
	end = start + len - 1;
	
	while (end >= start)
	{
		temp = tolower(*start);
		*start = tolower(*end);
		*end = tolower(temp);
		++start;
		--end;
	}
}

void StringReverseTest()
{
	char *src = "Hello, it's me!";
	StringReverse(src);
} 


