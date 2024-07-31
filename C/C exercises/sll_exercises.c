#include <stdio.h>/*printf*/
#include <stdlib.h>/*malloc*/
#include <assert.h> /*assert*/
/*#include  <sl_exercise.h>*/

typedef struct node
{
	void *data;
	struct node *next;
}node_t;

node_t *Flip(node_t* node);
int IsLoop(node_t *node);
node_t *FindIntersection(node_t *node_one, node_t *node_two);
node_t *NNodeFromEnd(node_t *node_one, size_t to_find);
void OpenLoop(node_t* node);

node_t *Flip(node_t* node)
{
	node_t *prev;
	node_t *current;
	node_t *temp_next;
	
	prev = NULL;
	current = node;
	
	while (current != NULL)
	{
		temp_next = current->next;
		current->next = prev;
		prev = current;
		current = temp_next;
	}
	
	return (prev);
}

int IsLoop(node_t *node)
{
	node_t* runner1 = NULL;
	node_t* runner2 = NULL;
	
	assert(node);
	
	runner1 = node;
	runner2 = node->next;
	
	while(NULL != runner2)
	{
		if (runner1 == runner2)
		{
			return(1);
		}
		runner1 = runner1->next;
		runner2 = runner2->next;
		if (NULL == runner2)
		{
			break;	
		}
		runner2 = runner2->next;
	}
	
	return(0);
}

node_t *FindIntersection(node_t *node_one, node_t *node_two)
{
	size_t counter1 = 0;
	size_t counter2 = 0;
	size_t run_times = 0;
	node_t *run_node = NULL;
	node_t *to_compare_node = NULL;
	node_t *start_one = NULL;
	node_t *start_two = NULL;
	
	assert(node_one);
	assert(node_two);	
	
	start_one = node_one;
	start_two = node_two;
	
	while (NULL != node_one)
	{
		++counter1;
		node_one = node_one->next;
	}
	
	while (NULL != node_two)
	{
		++counter2;
		node_two = node_two->next;
	}
	
	if (counter1 >= counter2)
	{
		run_node = start_one;
		to_compare_node = start_two;
		run_times = counter1 - counter2;
	}
	else
	{
		run_node = start_two;
		to_compare_node = start_one;
		run_times = counter2 - counter1;
	}

	while (0 != run_times)
	{
		--run_times;
		run_node = run_node->next;
	}
	
	while(NULL != run_node)
	{
		if (run_node == to_compare_node)
		{
			printf("there is intersection\n");
			return (run_node);
		}
		run_node = run_node->next;
		to_compare_node = to_compare_node->next;
	}
	
	printf("no intersection\n");
	return (run_node);
}

node_t *NNodeFromEnd(node_t *node_one, size_t to_find)
{
	size_t counter = 1;
	node_t *start = NULL;
	node_t *runner = NULL;
	
	start = node_one;
	runner = node_one;
	
	while (counter <= to_find)
	{
		++counter;
		runner = runner->next;
	}
	
	printf("iterated through %i nodes\n", counter-1);
	
	--counter;
	
	while(0 != counter)
	{
		printf("start is now at %p\n", start);
		printf("start->next %p\n", (start->next));
		--counter;
		start  = start->next;
		runner = runner->next;		
	}	
	
	while(NULL != runner)
	{
		start  = start->next;
		runner = runner->next;
	}

	printf("node 2 from the end is %p\n", start);
	printf("node next %p\n", (start->next));
	return (start);

}

void OpenLoop(node_t *node)
{
	node_t *slow = NULL, *fast = NULL;
	
	assert(node);
	
	slow = node;
	fast = node->next;
	
	while (slow->next != (fast->next)->next)
	{
		slow = slow->next;
		fast = (fast->next)->next;
	}
	
	slow->next = NULL;
}

void OpenIntersection(node_t *head1, node_t *head2)
{
	size_t count1 = 0, count2 = 0;
	node_t *run1 = NULL, *run2 = NULL;
	int run1_flag = 1, run2_flag = 2;
	
	assert(head1);
	assert(head2);
	
	run1 = head1;
	run2 = head2;
	
	while (run1->next != run2->next)
	{
		run1 = run1->next; 
		run2 = run2->next;
		
		if (NULL == run1->next)
		{
			if (1 == run1_flag)
			{
				run1_flag = 2;
				run1 = head2;
			}
			else
			{
				run1_flag = 1;
				run1 = head1;
			}
		}
		
		if (NULL == run2->next)
		{
			if (2 == run2_flag)
			{
				run2_flag = 1;
				run2 = head1;
			}
			else
			{
				run2_flag = 2;
				run2 = head2;
			}
		}
		
	}
	
	run1->next = NULL;
}

int main()
{
	node_t node1;
	node_t node2;
	node_t node3;
	node_t node4;
	node_t node5;
	node_t node6;
	node_t node7;
	node_t node8;
	node_t node9;
	
	node_t node1_list_two;
	node_t node2_list_two;
	node_t node3_list_two;
	size_t to_find = 2;
	int is_loop = 0;
	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	/*node6.next = NULL;*/
	node6.next = &node7;
	node7.next = &node8;
	node8.next = &node9;
	node9.next = &node4;

	is_loop = IsLoop(&node1);
	
	if(is_loop)
	{
		printf("the node list is loop\n");
	}
	else
	{
		printf("the node list is not loop\n");
	}
	
	OpenLoop(&node1);
	
	is_loop = IsLoop(&node1);
	if(is_loop)
	{
		printf("the node list is loop\n");
	}
	else
	{
		printf("the node list is not loop\n");
	}
	
	node1_list_two.next = &node2_list_two; 
	node2_list_two.next = &node3_list_two;
	node3_list_two.next = &node5;
	
	is_loop = IsLoop(&node1);
	if(is_loop)
	{
		printf("the node list is loop\n");
	}
	else
	{
		printf("the node list is not loop\n");
	}
	node6.next = NULL;
	
	FindIntersection(&node1, &node1_list_two);
	OpenIntersection(&node1, &node1_list_two);
	FindIntersection(&node1, &node1_list_two);
	NNodeFromEnd(&node1, to_find);
	return(0);
}



