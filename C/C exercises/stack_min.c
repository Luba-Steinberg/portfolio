#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct stack_wrap
{
	int stack[1000];
	int min[1000];
	size_t stack_size;
	size_t min_size;
};

typedef struct stack_wrap stack_wrap_t;

stack_wrap_t *StackWrapPush(stack_wrap_t *stack_wrapper, int num)
{
	assert(stack_wrapper);
	
	if (0 == stack_wrapper->stack_size)
	{
		stack_wrapper->min[stack_wrapper->min_size] = num;
		++stack_wrapper->min_size;
	}
	
	stack_wrapper->stack[stack_wrapper->stack_size] = num;
	++(stack_wrapper->stack_size);
	
	if (stack_wrapper->min[(stack_wrapper->min_size) - 1] >= num)
	{
		stack_wrapper->min[stack_wrapper->min_size] = num;
		++stack_wrapper->min_size;
	} 
	
	printf("last element in stack is %i\n", stack_wrapper->stack[(stack_wrapper->stack_size)-1]);
	printf("last element in min arr is %i\n", stack_wrapper->min[(stack_wrapper->min_size)-1]);
	printf("min arr size is %lu\n", stack_wrapper->min_size);
	return(stack_wrapper);
}

int main()
{
	stack_wrap_t *stack_wrap1 = NULL;
	stack_wrap1 = (stack_wrap_t *)malloc(sizeof(stack_wrap_t));
	
	if(NULL == stack_wrap1)
	{
		printf("malloc didn't succeed");
	}
	else
	{
		printf("stack wraper exists");
	}
	
	stack_wrap1->stack_size = 0;
	stack_wrap1->min_size = 0;
	
	StackWrapPush(stack_wrap1, 20);
	StackWrapPush(stack_wrap1, 10);
	StackWrapPush(stack_wrap1, 30);
	StackWrapPush(stack_wrap1, 4);
	StackWrapPush(stack_wrap1, 2);
	StackWrapPush(stack_wrap1, 2);
	StackWrapPush(stack_wrap1, 1000);
	
	return (0);
}
