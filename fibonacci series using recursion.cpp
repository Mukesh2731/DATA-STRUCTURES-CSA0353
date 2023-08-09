#include<stdio.h>
int main()
{
	int i,n1=0,n2=1,n3,number;
	printf("Enter the number:");
	scanf("%d",&number);
	for(i=1;i<=number;++i)
	{
		printf("%d ",n1);
		n3=n1+n2;
		n1=n2;
		n2=n3;
	}
	return 0;
}