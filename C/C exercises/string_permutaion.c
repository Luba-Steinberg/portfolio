#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int factorial(int n)
{
    int fact=1;
    for(int i=2;i<=n;i++)
        fact*=i;
    return fact;
}

void swap(int i,int j)
{
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}

void main()
{
    char *str;
    size_t j, i;
    len=strlen(str);
    fact=factorial(len);
    for(i=0;i<fact;i++)
    {
        j=i%(len-1);
        swap(j,j+1);
        
        for (k = 0; k < size; ++k){
    		for(j = 0; j < size; ++j)
    		{
        	printf("%c",word[k][j]);
    		}
    		printf("\n");
	}
}
