#include <stdio.h>

#define MAX_TWO(a, b) ((a > b) ? a : b)
#define MAX_THREE(a, b, c) (MAX_TWO(a, b) > c ? MAX_TWO(a, b) : c)
#define SIZEOF_VAR(a) ((size_t)(&(a)+1)-(size_t)(&(a)))
#define SIZEOF_TYPE(type) ((type *)0+1)

int main()
{
	int a = 8;
	int b = 15;
	int c = 20;
	int max = MAX_TWO(a,b);
	int max_three = MAX_THREE(a,b,c);
	size_t size = 0;
	size_t size_type = 0;
	
	size  = SIZEOF_VAR(a);
	size_type = (size_t)SIZEOF_TYPE(long);
	printf("the max num is %d\n", max);
	printf("the max num between three nums is %d\n", max_three);
	printf("the size of num is %lu\n", size);
	printf("the size of int is %lu\n", size_type);
	
	return (0);
} 
