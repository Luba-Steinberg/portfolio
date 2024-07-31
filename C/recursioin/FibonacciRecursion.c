#include <stddef.h>/*size_t*/
#include <stdio.h>

int FibonacciRecursive(size_t index)
{
    if (0 == index)
    {
        return (0);
    }

    if (1 == index)
    {
        return (1);
    }

    return( (FibonacciRecursive(index - 1)) + (FibonacciRecursive(index - 2)));
}

int FibonacciIterative(size_t index)
{
    int num1 = 0, num2 = 1, result = 0;
    size_t counter = 1;

    if (0 == index)
    {
        return (0);
    }

    if (1 == index)
    {
        return (1);
    }

    while (counter < index)
    {
        ++counter;
        result = num1 + num2;
        num1 = num2;
        num2 = result;
    }

    return (result);
}

int main()
{
    size_t index = 9;

    printf("******************Iterative Fibonacci Test***************\n");
    printf("the Fibonacci value of index 9 expected: 34;\n returned value on index %lu is %d\n", index, FibonacciIterative(index));
    printf("******************Recursive Fibonacci Test***************\n");
    printf("the Fibonacci value of index 9 expected; 34;\n returned value on index %lu is %d\n", index, FibonacciRecursive(index));

    return (0);
}