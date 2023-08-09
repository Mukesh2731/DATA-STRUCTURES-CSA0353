#include<stdio.h>
int main()
{
	int a[10],i;
	printf("Enter the values:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Even numbers are:");
	for(i=0;i<10;i++)
	{
		if(a[i]%2==0)
		printf("%d ",a[i]);
	}
	printf("\nOdd numbers are:");
	for(i=0;i<10;i++)
	{
		if(a[i]%2==1)
		printf("%d ",a[i]);
	}
	return 0;
}