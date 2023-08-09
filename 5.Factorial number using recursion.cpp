#include<stdio.h>
int main()
{
	int i,f=1,num;
	printf("Enter the number:");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		f=f*i;
	}
	printf("Factorial of %d:%d",num,f);
	return 0;
}