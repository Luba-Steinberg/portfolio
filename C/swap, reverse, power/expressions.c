#include <stdio.h>
#include <stdlib.h>

int Hello_World();
int Power_Func();
double Power_func(int power_num);
int Reverse_Func();
int Reverse_func(int num_to_rev);
int Swap_Func();
int Swap_func(int *num1_ptr, int *num2_ptr);


int main()
{
	Hello_World();
	Power_Func_Test();
	Reverse_Func_Test();
	Swap_Func_Test();
	
	return (0);
}

int Hello_Word()
{
	char *str[]={"22", "68", "65", "6c", "6c", "6f", "20", "77", "6f", "72", "6c", "64", "22"};
	int i = 0;
	int str_size=sizeof(str)/sizeof(str[0]);
	 printf("\n");
	 for (i = 0; i< str_size; ++i)
	 {
	printf("%c", (char)strtoul(str[i], NULL, 16)); 
	}
	return 0;
}

int Power_Func_Test()
{
	int power_num;
	double result = 0;
	
	scanf("%d", &power_num);	
	
	result = Power_func(power_num);
	
	printf("%.5f \n", result);
	
	return 0;
}

double Power_func(int power_num)
{	
	double num = 1;
	int i = 0;
	float base = 10.0;
	
	if (power_num<0)
	{
		base=1/base;
		power_num=-power_num;
	}
	
	while (i<power_num)
	{
		num *= base;
		i++;
	}
	
	return num;
}
	
int Reverse_Func_Test()
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
	

int Swap_Func_Test()
{
	int num1 = 0;
	
	scanf("%d", &num1); 
	scanf("%d", &num2); 
		
	Swap_func(&num1, &num2);
	
	printf("The swapped numbers in main are %d and %d \n", num1, num2);
	
	return 0;
}

int Swap_func(int *num1_ptr, int *num2_ptr)
{
	int temp = 0;
		
	temp = *num1_ptr;
	*num1_ptr = *num2_ptr;
	*num2_ptr = temp;
		
	printf("The swapped numbers in subfunc are %d and %d \n", *num1_ptr, *num2_ptr);

	return 0;
}
