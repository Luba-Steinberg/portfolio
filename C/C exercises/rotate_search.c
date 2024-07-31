#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

int IsRotation(char *str1, char *str2);

int main()
{
	char str1[] = "12345";
	char str2[] = "54123";
	int result = 0;
	
	result = IsRotation(str1, str2);
	if (1 == result)
	{
		printf("The second string is rotation");
	}
	else 
	{
		printf("The second string is NOT a rotation");
	}
	
	return (0);
}

int IsRotation(char *str1, char *str2)
{
	size_t str1_length = 0, str2_length = 0;
	char temp = '0';
	size_t i = 0, j = 0;
	int cmp_result = 0;
	
	assert (NULL != str1);
	assert (NULL != str2);
	
	str1_length = strlen(str1);
	str2_length = strlen(str2);
	if (str1_length != str2_length) 
	{
		return(0);
	}
	for (i = 0; i < str1_length; ++i)
	{
		cmp_result = strcmp(str1, str2);
		if (0 == cmp_result)
		{
			return (1);
		}
		else 
		{
			for (j = 0; j < str1_length-1; ++j)
			{
				temp = str1[j];
				str1[j] = str1[j+1];
				str1[j+1] = temp;
			}
		}
	}
	
	return (0);
}
