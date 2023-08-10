#include<stdio.h>
int linearsearch(int arr[],int size,int target){

		for(int i=0;i<size;i++){
			if(arr[i]==target){
				return i;
			}
		}
		return -1;
	}
	int main(){
	
	int arr[]={5,2,4,6,23,56,43};
	int size=sizeof(arr) /sizeof(arr[0]);
	int target;
	printf("Enter the number to search:");
	scanf("%d",&target);
	int index=linearsearch(arr,size,target);
	if(index != -1){
		printf("Number %d found at index %d",target,index);
	}
	else
	{
		printf("Number %d not found in array");
	}
	return 0;
}