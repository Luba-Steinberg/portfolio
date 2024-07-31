#include <stddef.h> /*size_t*/
#include <string.h> /*strlen*/
#include <stdio.h> /*printf*/

int ChechNulls(char *str)
{
	size_t len = 0;
	
	len = strlen(str);
	
	if (0 == len || '0' != *str)
	{
		return (0);
	}
	
	++str;
	
	while ('\0' != *str)
	{
		++str;
	}

	--str;
	
	if ('0' != *str)
	{
		return (0);
	}
	
	return (1);
}

int CheckNulls(char *str)
{
	int state = 0;
	enum 
	{
		q1, q2, q3, qa
	};
	

	int state_arr[4][2] = {{q3, q2}, {q2, q2}, {qa, q3}, {qa, q3}};

	while ('\0' != *str)
	{
		state = state_arr[state][*str - '0'];
		++str;
	}
	
	if (qa == state)
	{
		return (1);
	}
	
	return (0);
	
}

int main()
{
	char str[] = "01111111";
	
	if (1 == CheckNulls(str))
	{
		printf("acceptable string\n"); 
	}
	else
	{
		printf("NON-acceptable string\n");
	}
	
	
	
	return (0);
}
