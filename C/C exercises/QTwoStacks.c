#include <assert.h> /*assert*/
#include <stddef.h>/*NULL*/
#include <string.h>/*memcpy*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/

typedef struct stack stack_t;
typedef struct q q_t;


q_t *QCreate(size_t capacity);
stack_t *StackCreate(size_t capacity);
int QPush(q_t *q, char *data);
int StackPourToStack(stack_t *oper_stack, stack_t *guard_stack, size_t elems_to_pour);
int StackPush(stack_t *stack, size_t offset, char *c);

struct q
{
	stack_t *oper_stack;
	stack_t *guard_stack;
	size_t capacity;
	size_t offset;
};

struct stack
{
	char elements[1];
};

int StackPourToStack(stack_t *oper_stack, stack_t *guard_stack, size_t elems_to_pour)
{
	int guard_counter = 0;
	
	assert(oper_stack);
	assert(guard_stack);
	
	while (elems_to_pour > 0)
	{
		*(char *)((guard_stack->elements) + guard_counter) = *(char *)((oper_stack->elements) + elems_to_pour - 1);
		--elems_to_pour;
		++guard_counter;
	}
	
	return (0);
}

int StackPush(stack_t *stack, size_t offset, char *c)
{
	assert(stack);
	
	memcpy(stack->elements + offset, c, 1);
	
	return(0);
}

int QPush(q_t *q, char *data)
{
	assert(q);
	
	assert(q->oper_stack);
	assert(q->guard_stack);
	
	if ((q->offset) == (q->capacity))
	{
		
		return (1);
	}
	else
	{
		StackPourToStack(q->oper_stack, q->guard_stack, q->offset);
	}
	
	if (0 == StackPush(q->guard_stack, q->offset, data))
	{
		++(q->offset);
		StackPourToStack(q->guard_stack, q->oper_stack, q->offset);
	}
	
	return (0);
}

stack_t *StackCreate(size_t capacity)
{
	stack_t *stack;
	
	stack = (stack_t *)malloc(sizeof(stack_t)+capacity);
	
	if (NULL == stack)
	{
		return(NULL);
	}
	
	return(stack);
}

q_t *QCreate(size_t capacity)
{
	q_t *q = NULL;
	
	q = (q_t *)malloc(sizeof(q));
	q->oper_stack = StackCreate(capacity);
	q->guard_stack = StackCreate(capacity);
	q->capacity = capacity;
	q->offset = 0;
	
	return(q);
}

int main()
{
	q_t *q1 = NULL;
	size_t capacity;
	char c1 = 'a';
	char *c1_p = &c1;
	char c2 = 'b';
	char *c2_p = &c2;
	char c3 = 'c';
	char *c3_p = &c3;
	char c4 = 'd';
	char *c4_p = &c4;
	char c5 = 'e';
	char *c5_p = &c5;
	
	q1 = QCreate(capacity);
	if (q1 == NULL)
	{
		printf ("q creation failed\n");
	}
	else
	{
		 printf("the stack was created\n");
	}
	
	QPush(q1, c1_p);
	QPush(q1, c2_p);
	QPush(q1, c3_p);
	QPush(q1, c4_p);
	QPush(q1, c5_p);
	
	return (0);
}
