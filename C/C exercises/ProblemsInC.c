#include <stdio.h>

int main()
{
	int num = 0;
	const int num2 = 6;
	const int num3 = num2 -5;
	char ch = 97;
	float num4;
	printf("num1 is %d \n", num);
	printf("enter a number \n");
	scanf("%d", &num);
	printf("100 devided by %i is %i \n", num, 100/num);
	
	printf("num3 is %i \n", num3);
	num = 4;
	num4 = (float)num;
	num++;
	printf("num1 is %i, num2 is %i, num3 is %i, num4 is %f, my char is %c\n", num, num2, num3, num4, ch);
	
	return(0);
}
	
	
