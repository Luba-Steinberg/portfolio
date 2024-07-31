#include <stdio.h>
#include <stdlib.h> /*for malloc*/
#include <string.h> /*for strncmp*/
#include <assert.h> /*for assert*/
#include <time.h> /*for date*/

#include "files.h"

#define ENTER (10)
#define BUFFER (100)
#define CHAIN (5) 

typedef void (*PrintFunc_Ptr)(int); 
typedef int (*LoggerFunc)(const char *, char*); 
typedef enum failures (*OperatingFuncType)(const char *, char*);

struct print_me
	{
		int num; 
		PrintFunc_Ptr PrintMePtr;
	};
struct log_inp
	{
		char *str;
		LoggerFunc CmpFunc;
		OperatingFuncType OperatingFunc;
	};

void Print();
enum failures Logger(const char *file_name, char *void_var);
int LoggerTest();

int LoggerPhaseTwoTest();
int Cmp(const char *funcStr, char *buffer);
enum failures Remove(const char *file, char *void_var);
enum failures Count(const char *file, char *void_var);
enum failures Exit(const char *void_var1, char *void_var2);
enum failures AppendToStart(const char *file, char *buffer);
int DefaultCmp(const char *void_var1, char *void_var2);

int main()
{
	StructuresTest();
	LoggerTest();
	LoggerPhaseTwoTest();
	LoggerPhaseTwo();
	
	return (0);
}

void Print(int num)
{
	printf("%i \n", num);
}

int StructuresTest()
{
	int i = 0;
	struct print_me print_meFuncsArray[ENTER];
	
	for (i = 0; i < ENTER; ++i)
	{
		print_meFuncsArray[i].num = i*ENTER;
		print_meFuncsArray[i].PrintMePtr = &Print;
	print_meFuncsArray[i].PrintMePtr(print_meFuncsArray[i].num);
	}
	return (0);
}

enum failures Logger(const char *file_name, char *buffer)
{
	FILE *fp = fopen(file_name, "a"); 
	int fputs_result;
	int fclose_result;
	
	if (NULL == fp)
	{
		return (OPEN);
	}
	
	fputs_result = fputs(buffer, fp);
	if (EOF == fputs_result)
	{
		return (APPEND);
	}
	
	fclose_result = fclose(fp);
	if (0 != fclose_result)
	{
		return (CLOSE);
	}

	return (SUCCESS);
}

int LoggerTest()
{
	char *file_name = "/home/libi/git/streamFile.txt";
	
	Logger(file_name, 0);
	return(0);
}

int Cmp(const char *funcStr, char *buffer)/*use strcmp instead*/
{
	int result = 0;
	size_t size = strlen(buffer);
	
	assert (NULL != buffer);
	result = strncmp(funcStr, buffer, size);
	return (result);
}

enum failures Remove(const char *file, char *void_var)
{
	int fremove_result;
	(void) void_var;
	
	fremove_result = remove(file);
	if (0 != fremove_result)
	{
		return (REMOVE);
	}
	printf("Deleted successfully\n");
	return (SUCCESS);
}

enum failures Count(const char *file_name, char *void_var)
{
	FILE *fp = fopen(file_name, "r");
	int c, counter = 0;
	(void) void_var;
	if (NULL == fp)
	{
		return (OPEN);
	}
	
	c = getc(fp);
	while (EOF != c)
	{
		if ('\n' == c) 
		{
			++counter;
		}
		c = getc(fp);
	}
	printf("hi");
	printf("There are %d lines in the file\n", counter);
	return (SUCCESS);
}

enum failures Exit(const char *void_var1, char *void_var2)
{
	(void) void_var1;
	(void) void_var2; 
	exit (SUCCESS);
}

enum failures AppendToStart(const char *file_name, char *buffer)
{
	FILE * fp;
	FILE * ftemp;
	char tempf_name[40];
	int fputs_result;
	int fclose_result;
	int fremove_result;
	int fcopy_result;
	int frename_result;
	char copy_ch;
	struct tm *timenow;

	time_t now = time(NULL);
	timenow = gmtime(&now);
	strftime(tempf_name, sizeof(tempf_name), "temp%Y-%m-%d_%H:%M:%S.txt", timenow);
	fp = fopen(file_name, "r");
	if (NULL == fp)
	{
		return (OPEN);
	}

	ftemp = fopen(tempf_name, "w");
	if (NULL == ftemp)
	{
		perror("Error in creating a temporary file\n");
		fclose_result = fclose(fp);
		if (EOF == fclose_result)
		{
			return (CLOSE);
		}
		return (CREATE);
	}
	++buffer;
	fputs_result = fputs(buffer, ftemp);
	if (EOF == fputs_result)
	{	
		fremove_result = remove(tempf_name);
		if (0 != fremove_result)
		{
			return (REMOVE);
		}
		return (APPEND);
	}
	

	copy_ch = fgetc(fp);
    	while (EOF != copy_ch) 
    	{ 
        	fcopy_result = fputc(copy_ch, ftemp);
        	
        	if (EOF == fcopy_result)
		{
			fremove_result = remove(tempf_name);
			if (0 != fremove_result)
			{
				return (REMOVE);
			}
			return (COPY);
		} 
		copy_ch = fgetc(fp);
    	}

	fclose_result = fclose(fp);
	if (EOF == fclose_result)
	{
		fremove_result = remove(tempf_name);
		if (0 != fremove_result)
		{
				return (REMOVE);
		}
		return (CLOSE);
	}
	
	fremove_result = remove(file_name);
	if (0 != fremove_result)
	{
		fremove_result = remove(tempf_name);
		if (0 != fremove_result)
		{
			return (REMOVE);
		}
		return (REMOVE);
	}
	

	fclose_result = fclose(ftemp);
	if (EOF == fclose_result)
	{
		return (CLOSE);
	}
	frename_result = rename(tempf_name, file_name);
	if (0 != frename_result)
	{
		return (RENAME);
	}
	return (SUCCESS);
}

int DefaultCmp(const char *void_var1, char *void_var2)
{
	(void) void_var1;
	(void) void_var2;
	return (0);
}

int AppendCmp(const char *funcStr, char *buffer)
{
	return (*funcStr - *buffer);
}

enum failures LoggerPhaseTwo()
{
	char *buffer;
	struct log_inp inpFuncArray[CHAIN];
	int i = 0;
	int comp_result = 0; 
	enum failures operating_status = SUCCESS;
	char *file_name = "streamFile.txt";
	
	buffer = (char *)malloc(BUFFER * sizeof(char));
	if (NULL == buffer)
	{
		operating_status = MALLOC;
		return (operating_status);
	}
	inpFuncArray[0].str = "-remove\n";
	inpFuncArray[0].CmpFunc = &Cmp;
	inpFuncArray[0].OperatingFunc = &Remove;
	inpFuncArray[1].str = "-count\n";
	inpFuncArray[1].CmpFunc = &Cmp;
	inpFuncArray[1].OperatingFunc = &Count;
	inpFuncArray[2].str = "-exit\n";
	inpFuncArray[2].CmpFunc = &Cmp;
	inpFuncArray[2].OperatingFunc = &Exit;
	inpFuncArray[3].str = "<";
	inpFuncArray[3].CmpFunc = &AppendCmp;
	inpFuncArray[3].OperatingFunc = &AppendToStart;
	inpFuncArray[4].str = " "; 
	inpFuncArray[4].CmpFunc = &DefaultCmp;
	inpFuncArray[4].OperatingFunc = &Logger;

	while (SUCCESS == operating_status)
	{
		printf("enter a string: ");
		fgets (buffer, 100, stdin);
		
		if (NULL == buffer)
		{
			printf("Error in reading the string\n");
			return (-1);
		}
		
		for (i = 0; i < CHAIN; ++i)
		{
			comp_result = inpFuncArray[i].CmpFunc(inpFuncArray[i].str, buffer);
			if (0 == comp_result)
			{
				operating_status = inpFuncArray[i].OperatingFunc(file_name, buffer);
				break;
			}
		}	
	}
	
	return (operating_status);
}

int LoggerPhaseTwoTest()
{
	
	char *file_name = "/home/libi/git/streamFile.txt";
	
	LoggerPhaseTwo(file_name);
	
	return(0);
}
