#include <stdio.h>

int main()
{
	char c = -1;
	unsigned int c_char = (unsigned)c;
	unsigned int i = 1;
	
	printf("The unsigned char c is %c", c);
	printf("The unsigned char c_char is %i", c_char);
	printf("The unsigned int c is %i", i);
	if (-1 < (unsigned char)1)
	printf("A");
	else 
	printf("B");
	
	if (-1 < (unsigned int)1)
	printf("C");
	else 
	printf("D");
	
	
	return(0);
}
	
	
