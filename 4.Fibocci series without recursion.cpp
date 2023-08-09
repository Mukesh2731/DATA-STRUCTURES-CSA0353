#include<stdio.h>
int main()
{
	int n1=0,n2=1,n3,i,number;
	printf("Enter the number:");
	scanf("%d",&number);
	printf("%d %d ",n1,n2);
	for(i=0;i<number;++i)
	{
		n3=n2+n1;
		printf("%d ",n3);
		n1=n2;
		n2=n3;
	}
	return 0;
}