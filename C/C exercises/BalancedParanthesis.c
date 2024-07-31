#include <stddef.h> /*size_t*/
#include <string.h> /*stlen*/
#include <stdio.h>/*printf*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h>	/* printf(), size_t */
#include <errno.h>	/* errno */
#include <string.h> /* strcmp() */


/******************************************************************************/
/*                          Color Defines   		                          */
/******************************************************************************/

#define PAREN(sym) (sym == ')' || sym == '}' || sym == ']' || sym == ')' || sym == '}' || sym == ']')

#define DEFAULT     "\033[0m"
#define BLACK       "\033[30m"             /* Black */
#define RED         "\033[31m"             /* Red */
#define GREEN       "\033[32m"             /* Green */
#define YELLOW      "\033[33m"             /* Yellow */
#define BLUE        "\033[34m"             /* Blue */
#define MAGENTA     "\033[35m"             /* Magenta */
#define CYAN        "\033[36m"             /* Cyan */
#define WHITE       "\033[37m"             /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

static size_t success_tests = 0;
static size_t fail_tests = 0;
static size_t all_tests = 0;

void TestInt(int result, int expected, char *message, int line);
int IsBalanced(char *str);
int IsPair(char *str1, char *str2);

void TestInt(int result, int expected, char *message, int line)
{
	++all_tests;
	if(result == expected)
	{
		++success_tests;
		printf(GREEN"%s SUCCESS"DEFAULT" --- line: %d\n",message, line);
	}
	else
	{
		++fail_tests;
		printf(MAGENTA"%s FAIL"DEFAULT" --- line: %d\n",message, line);
	}
}

int IsBalanced(char *str)
{
	char *check_vector = NULL;
	char *check_vector_start = NULL;
	
	assert(str);
	
	check_vector = (char *)malloc(strlen(str));
	if (NULL == check_vector)
	{
		return (-1);
	}
	
	check_vector_start = check_vector;
	
	if (*str == ')' || *str == '}' || *str == ']')
	{
		return (0);
	}
	
	while('\0' != *str)
	{		
		if (*str == '(' || *str == '{' || *str == '[' || *str == ')' || *str == '}' || *str == ']')
		{
			*check_vector = *str;
			++str;
			if (*(check_vector) == ')' || *(check_vector) == '}' || *(check_vector) == ']')
			{
				if (IsPair(check_vector - 1, check_vector))
				{
					check_vector = check_vector -1;
				}
				else 
				{
					return (0);
				}	
			}		
			++check_vector;

		}
		++str;
	}
	
	return (check_vector == check_vector_start);
}

int IsPair(char *str1, char *str2)
{
	if ((*str1 == '(' && *str2 == ')') || (*str1 == '{' && *str2 == '}') || (*str1 == '[' && *str2 == ']'))
	{
		return (1);
	}
	
	return (0); 
}

int main()
{
	char *str = "{()}{([{}])}";
	char *str2 = "{()}{[{}])}";
	size_t length = strlen(str);
	int status = 0;
	
	status = IsBalanced(str);
	TestInt(status, 1, "the string has balanced paranthesis", __LINE__);
	
	status = IsBalanced(str2);
	TestInt(status, 0, "the string does NOT have balanced paranthesis", __LINE__);
	
	return (0);
}
