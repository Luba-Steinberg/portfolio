#include <stddef.h> /*NULL*/
#include <stdio.h>

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

node_t *FlipSLL(node_t *node)
{
    node_t *new_head = NULL;

    if (NULL == node->next)
    {
        return (node);
    }

    new_head = FlipSLL(node->next);

    (node->next)->next = node;

    node->next = NULL; /*temporary*/

    return (new_head);
}

int main()
{
    int nums[9] = {0};
    size_t i = 0;
    node_t nodes[9] = {NULL};

    for (i = 0; i < 9; ++i)
    {
        nodes[i].next = &(nodes[i+1]);
        nums[i] = i;
        nodes[i].data = &(nums[i]);
        printf("the value of node on place %lu is %d\n", i, *(int *)nodes[i].data);
    }
    
    nodes[8].next = NULL;

    printf("***************FLIP SLL TEST*******************");
    printf("before flip the value of node on index 0 is %d\n", *(int *)(nodes[0].data));
    
    printf("after flip the value of node on index 0 is %d\n", *(int *)((*(FlipSLL(&(nodes[0])))).data));

    return (0);
}