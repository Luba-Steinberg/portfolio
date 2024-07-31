/***************************/
/*Name: Luba Steinberg     */
/*Date: 1.04.2024          */
/*Reviewer: Lior Shalom    */
/***************************/

#include <stdio.h>/*printf*/
#include <assert.h>/*assert*/
#include <string.h>/*strlen*/
#include <stdlib.h>/*malloc*/
#include <stddef.h>/*size_t*/

#define CHECK_ENDIANNESS ((*((short *)"\x01\0")) == 1 ? 1 : 0)
#define IS_NUM(num) ((0 <= num && 9 >= num) ? 1 : 0)
#define NUM_SIGN(ch) ((ch >= '0' && ch <= '9') ? 1 : 0)
char *Itoa_base10(int num_to_str, char *dest, int base);/*conversts int to string for base 10, recieves int, destination pointer and base 10, returns destination string, complexity O(n)*/
int Atoi_base10(const char *str);/* converts string to integer, recieves a pointer to a string, returns integer, have to check whether the string pointer is not empty, complexity of O(n)*/
char *Itoa(int num_to_str, char *dest, int base);/*converts integer to a string for any base; recieves integer, destination string pointer, base complexity if O(n)*/
/* int Atoi(const char *str, int base);*/
char *RepeatedSymbols(const char *str1, size_t str1_len, const char *str2, size_t str2_len, const char *str3, size_t str3_len); /*checks symbols that are present in first two strings are not in the third strings; receives three strings and their sizes; complexity of O(n)*/
static char *Reverse(char *str); /*receives a pointer to string, returns a pointer to the beginning of the reversed string*/

void IntStrFuncs()
{
	const int num_to_str = 321654987;
 	char *str_from_nums = (char *)malloc(sizeof(char)*20);
	const char *str = "-987654aAjHGGF8976";
 	int nums_in_string = 0;
 	const int num2_to_str = -256;
 	char *str2_from_nums = (char *)malloc(sizeof(char)*20);
	char *str3_from_nums = "61";
	int num3 = 0;
 	char *str_check1 = "abcdeDFfwxyz";
 	size_t str1_len = strlen(str_check1);
	char *str_check2 = "aDFbJKHlmnMOPJopqrstuLKMNJHvwxyz";
	size_t str2_len = strlen(str_check2);
	char *str_check3 = "mnMOPJopqrstu";
	size_t str3_len = strlen(str_check3);
	int base = 10;
 	
 	Itoa_base10(num_to_str, str_from_nums, 10);
 	printf("%s", str_from_nums);
	Itoa(num2_to_str, str2_from_nums, base);
	printf("%s", str2_from_nums);
	RepeatedSymbols(str_check1, str1_len, str_check2, str2_len, str_check3, str3_len);
	nums_in_string = Atoi_base10(str);
	printf("%i\n", nums_in_string);
	num3 = CHECK_ENDIANNESS;
	printf("%i", num3);
	free(str_from_nums);
	free(str2_from_nums);
}

char *Itoa_base10(int num_to_str, char *dest, int base)
{
	int flag = 0;
 	int remainder = 0, counter = 0;
 	char temp = 0;
 	char *start = NULL;
 	char *end = NULL;
 	char *dest_return = NULL;
 	
 	assert(NULL != dest);
 	
 	start = dest;
	
	if (0 == num_to_str)
	{
		*dest = '0'; 
		++dest;
		*dest = '\0';
		return (dest);
	}
	
	if (num_to_str < 0)
	{
		flag = 1;
		num_to_str *= (-1);
	}
	
	while (0 != num_to_str)
	{
		remainder =  num_to_str % base;
		*dest = remainder + '0';
		++dest;
		num_to_str = (num_to_str - remainder) / base;
 		++counter;
	}
	
	if (1 == flag)
	{
		*dest = '-';
 		++counter;
 		++dest;
	}
	
	*dest = '\0';
 	++*dest;
 	
 	end = dest-1;
 	
 	dest_return = Reverse(start);
 	
	return(dest_return);
}

int Atoi_base10(const char *str)
{
	int flag = 0;
	int final_num = 0;
	
	if ('-' == *str)
	{
		flag = 1;
		++str;
	}
	
	if ('+' == *str)
	{
		++str;
	}
	 
	while (NUM_SIGN(*str) && '\0' != *str)
	{ 
		final_num = final_num*10 + (*str - '0');
		++str;
	}
	
	if (flag == 1)
	{
		final_num *= (-1);
	}
	return (final_num);
}

char *Itoa(int num_to_str, char *dest, int base)
{
	int flag = 0;
 	int remainder = 0;
 	int temp = num_to_str;
 	char *start = NULL;
 	char *end = NULL;
 	char *runner = NULL;
 	
 	assert(NULL != dest);
 	
 	start = dest;
	runner = dest;
	
	if (0 == temp)
	{
		*runner = '0'; 
		return (dest);
	}
	
	if (temp < 0)
	{
		flag = 1;
		temp = -temp;
	}
	
	while (0 != temp)
	{
		remainder =  temp % base;
		if (IS_NUM(remainder))
		{ 
			*runner = remainder + '0';
		}
		else
		{
			*runner = remainder - 10  + 'a';
		}
	
		++runner;
		temp = temp / base;
	}
	
	if (1 == flag)
	{
		*runner = '-';
 		++runner;
	}
	
	*runner = '\0';
 	
 	end = runner - 1;
 	
 	start = Reverse(dest);
 	
	return(start);
}

static char *Reverse(char *str)
{
	char *start = NULL;
	char *end = NULL;
	int str_length = 0;
	char temp;
	
	assert(str);
	
	str_length = strlen(str);
	
	start = str;
	end = str + str_length - 1;
	
	while (end >= start)
 	{
 		temp = *start;
 		*start = *end;
 		*end = temp;
 		++start;
 		--end;
 	}
 	
 	return(str);
}

int Atoi(const char *str, int base)
{
	long int num = 0;
	int flag = 0;
 	
	assert(NULL != str);

	if ('-' == *str)
	{
		flag = 1;
		++str;
	}

	while ('\0' != *str)
	{
		if ('0' <= *str && '9' >= *str)
		{
		
			num = num * base + (*str - '0');
			++str;
		}
		else 
		{
			num = num * base + (*str + 10 - 'a'); 
			++str;
		}
	}
	
	if (1 == flag)
	{
		num = -1*num;
	}
	
	return (num);
}

char *RepeatedSymbols(const char *str1, size_t str1_length, const char *str2, size_t str2_length, const char *str3, size_t str3_length)
{
	char LUT[256];
	int i = 0;
	
	assert(NULL != str1);
	assert(NULL != str2);
	assert(NULL != str3);

	for (i = 0; i < str1_length; ++i)
	{
		LUT[str1[i]] = 1;	
	}
	
	for (i = 0; i < str3_length; ++i)
	{
		LUT[str3[i]] = 0;	
	}
	
	for (i = 0; i < str2_length; ++i)
	{
		if (1 == LUT[str2[i]])
		{
			printf("%c\n", str2[i]);
		}
	}	
}

int IsBigEndian()
{
	unsigned int i = 1;
	char *c = (char*)&i;
	if (*c)   
       	{
       		printf("Little endian\n");
       		return (0);
       	}
   	else
   	{
	   	printf("Big endian\n");
   		return(1);
   	}
}

int IsAtoiOutputSame()
{	
	char *str1_from_nums = "-987654aAjHGGF8976";
	int num1 = 0;
	int num2 = 0;
	
	num1 = Atoi_base10(str1_from_nums);
	num2 = atoi(str1_from_nums);
	
	return ((num1 == num2) ? 1 : 0);
}

