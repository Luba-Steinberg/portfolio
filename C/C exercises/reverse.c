#include <stdio.h>
#include <stdlib.h>


int Reverse_func(int num_to_rev);

int main()
{
	int num_to_rev = 0;
	int reversed_num = 0;
	
	scanf("%d", &num_to_rev); 
	
	reversed_num = Reverse_func(num_to_rev);
	
	printf("The reversed number in main is %.d \n", reversed_num);
	
	return 0;
}

int Reverse_func(int num_to_rev)
	{
		int digit1=0, digit2=0, digit3=0, result=0;
		
		digit3 = num_to_rev%10;
		num_to_rev = (num_to_rev-digit3) / 10;
		digit2 = num_to_rev%10;
		num_to_rev = num_to_rev - digit2;
		digit1=num_to_rev/10;
		
		result = digit3*100 + digit2*10 + digit1;
		
		printf("The reversed number in subfunc is %i \n", result);
		
		return result; 
	}
