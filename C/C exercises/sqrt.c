#include <stdio.h> /*printf*/

#define EPSILON (1.0/10000000000000) 

double SQRTfunc(double num)
{
	double lowest = 0, highest = num, middle = 0;
	
	if (num == (double)1)
	{
		return ((double)1); 
	}
	
	middle = (lowest + highest) / 2;
	
	while (middle*middle > num + EPSILON || middle*middle < num - EPSILON)
	{
		if (middle*middle > num + EPSILON)
		{
			highest = middle;
		}
		else
		{
			lowest = middle;
		}
		
		middle = (lowest + highest) / 2;
	}
	
	return ((double)middle);
}

int main()
{
	double num = 2.5, root = 0;
	
	root = SQRTfunc(num);
	printf("the root of %f is %f", num, root);
		
	return (0);
}
