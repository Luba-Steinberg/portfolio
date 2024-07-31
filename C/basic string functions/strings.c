#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

size_t StrLen(const char *str);
void StrCpy(char *dest, const char *src1);
void StrCpyTest();
void StrnCpy(char *dest, const char *src, size_t n);
void StrnCpyTest();
int StrnCmp(const char *s1, const char *s2, size_t n);
void StrnCmpTest();
int StrnCaseCmp(const char *s1, const char *s2);
void StrnCaseCmpTest();
char *StrChr(const char *s, int c);
void StrChrTest();
char *StrDup(const char *s);
int StrDupTest();
void StrCat(char *dest, const char *src);
void StrCatTest();
void StrnCat(char *dest, const char *src, size_t n);
void StrnCatTest();
int StrSpn(const char *s, const char *accept);
void StrSpnTest();
char *StrStr(const char *string_1, const char *string_2);
int StrStrTest();

int StrPalindrome(const char *s);
void StrPalindromeTest();

void StrSpace(char *s);
void StrSpaceTest();

int main()
{
	StrCpyTest();
	StrnCpyTest();
	StrnCmpTest();
	StrnCaseCmpTest();
	StrChrTest();
	StrDupTest();
	StrCatTest();
	StrnCatTest();
	StrStrTest();
	StrSpnTest();
	StrPalindromeTest();
	StrSpaceTest();
	
	return 0;
}

size_t StrLen(const char *str)
{
	const char *first_member = str;
	
	assert (NULL != str);

	while ('\0' != *str)
	{
		str++;
	}
	
	return str - first_member;
}

void StrCpy(char *dest, const char *src)
{	
	assert(NULL != dest);
	assert(NULL != src);
	
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	
	*dest = '\0';
}

void StrCpyTest()
{
	const char *str1=("Hello");
	char *str2=(char*)malloc(StrLen(str1)*4);
	
	printf("The original string is %s \n", str1);
	StrCpy(str2, str1);
	printf("The copied string is %s \n", str2);
	
}

void StrnCpy(char *dest, const char *src, size_t n)
{	
	assert(NULL != dest);
	assert(NULL != src);
	
	while ('\0' != *src  && n > 0)
	{
		*dest = *src;
		++src;
		++dest;
		--n;
	}
	
	while (0 != n)
	{
	*dest = '\0';
	++dest;
	--n;
	}
}

void StrnCpyTest()
{
	const char *src=("Hello, world!");
	char *dest=(char*)malloc(StrLen(src)*4);
	size_t size = 5;
	
	printf("The original string is %s \n", src);
	StrnCpy(dest, src, size);
	printf("The copied string is %s \n", dest);
};

int StrnCmp(const char *s1, const char *s2, size_t n)
{	  	 
	assert (NULL != s1);
	assert (NULL != s2);
	while (*s1 == *s2 && n>0)
		{
		if ('\0' == *s1)
		{
			return 0;
		}
		
			++s1;
			++s2;
			--n;
			
		if (0 == n)
		{
			return 0;
		}
		
		}
	printf("The result of comparison in strncmp %d", *s1-*s2);
	return (*s1-*s2);

}

void StrnCmpTest()
{
	char *s1 = "Hello";
	char *s2 = "Hella";
	size_t size = 5;
	int result;

	result = StrnCmp(s1, s2, size);
	printf("The result of comparison in test %i", result);
}

int StrnCaseCmp(const char *s1, const char *s2)
{
	assert (NULL != s1);
	assert (NULL != s2);
	while ('\0' != *s1 && '\0' != *s2 && tolower(*s1)==tolower(*s1))
		{
			++s1;
			++s2;	
		}
	return *s1-*s2;
}

void StrnCaseCmpTest()
{
	char *array_1 = "Hello, you";
	char *array_2 = "HeLLo, me";
	int result = 0;
	
	result = StrnCaseCmp(array_1, array_2);	
	printf("result of StrnCaseCmp in Test is %d", result);
}

char *StrChr(const char *s, int c)
{
	assert (NULL != s);
	
	while ('\0' != *s && *s != c)
	{	
		++s;
	}
	
	printf("The string is %s \n", s);
	return (char *)s;
}

void StrChrTest()
{
	char *string = "Hello, you";
	char char_find = 'l';
	char *char_ptr;
	
	char_ptr = StrChr(string, char_find);
	printf("The string in test is %s", char_ptr);
}

char *StrDup(const char *s)
{
	char *dest = (char*)malloc(StrLen(s));
	StrCpy(dest, s);
	return (char *)dest; 
}

int StrDupTest()
{	
	char *string = "Hello, you";
	StrDup(string);
 	printf ("The duplicated string is %s", string);
}

void StrCat(char *dest, const char *src)
{
	assert (NULL != dest);
	assert (NULL != src);
	
	while ('\0' != *dest)
		{
			++dest;
		}
		
	StrCpy(dest, src);

	printf("The new string is %s", dest);

}

void StrCatTest()
{
	char dest[30] = "Hello! ";
	char *src = "How are you?";
	
	StrCat(dest, src);
	printf("The new string is %s", dest);
}

void StrnCat(char *dest, const char *src, size_t n)
{	
	assert (NULL != dest);
	assert (NULL != src);
	
	while ('\0' != *dest)
		{
			++dest;
		}
		
	while ('\0' != *src && '\0' != n)
		{
			*dest = *src;
			++dest;
			++src;
			--n;
		}

	*dest = '\0';
	printf("The new string is %s", dest);
}


void StrnCatTest()
{
	char dest[30] = "Hello! ";
	char *src = "How are you?";
	size_t n = 3;
	
	StrnCat(dest, src, n);
	printf("The merged string is %s", dest);
}

char *StrStr(const char *haystack, const char *needle)
{
	size_t needle_length = StrLen(needle);
	
	assert (NULL != haystack);
	assert (NULL != needle);
	
	while ('\0' != *haystack)
	{
	
		if (0 == StrnCmp(haystack, needle, needle_length))
		{
			return (char *)haystack;
		}
		++haystack;
	}
	
	return NULL;

}

int StrStrTest()
{
 	const char *haystack = "Hello! How are you today?";
	const char *needle = "How";
	char *ptr = (char *)malloc(StrLen(haystack)*1);
	
	ptr = StrStr(haystack, needle);
	printf("the first occurance of how is %s", ptr);
	
}

int StrSpn(const char *s, const char *accept)
{
	int counter = 0;
	size_t size = 1;
	
	while ('\0' != *s)
	{
		int length = StrLen(accept);
		int i = 0;
		
		while ('\0' != *s)
		{
		 for (i = 0; i<length; ++i)
		 {
		 	if (*s == accept[i])
		 	{
		 		return counter;
		 	}	
		 } 
		 ++counter;
		 ++s;
		}
	}
	return counter;
}

void StrSpnTest()
{
	const char *s = "JKLMPTY39147";
	const char *accept = "01234567";
	int result = StrSpn(s, accept);
	
	printf("The result is %i bytes", result);
}

int StrPalindrome(const char *s)
{
	size_t size = StrLen(s);
	size_t i = 0;
	int flag = 1;
	const char *end;
	end = s;
	while (end>s)
	{
		if (*end == *s)
		{
		flag = 0;
		}
	}
	printf("the flag is %i", flag);
	return flag;
}

void StrPalindromeTest()
{
	char s[5] = "level";
	printf("Hi");
	int is_pal = StrPalindrome(s);
	
	if (1 == is_pal)
	{
		printf("The word is palindrome");
	}
	else 
	{
		printf("The word is not a palindrome");
	}
}

void StrSpace(char *str)
{
	char *reader = NULL;
	char *writer = NULL;
	char space = ' ';
	char temp = 0;

	assert(NULL != str);
	reader = str;
	writer = str;
	
	while(space == *reader)
	{
		++reader;
	}
	
	*writer = *reader;
	++writer;
	++reader;
	
	while('\0' != *reader)
	{
		if (space == *reader)
		{
			if (space == *writer)
			{
				*writer = *reader;
				++writer;
				++reader;
			}
			else
			{
			++reader;
			}
		}
		else 
		{
			*writer = *reader;
			++writer;
			++reader;
		}
	}	
}


void StrSpaceTest()
{
	char str[17] = " Hello,  world ! ";
	StrSpace(str);
	printf("The formated string is %s", str);
}
