#include<stdio.h>
#include<limits.h>
int main()
{
	int n;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int arr2[n];
	arr2[0]=arr[0];
	printf("The prefix sum is :");
	//printf(" %d",arr[0]);
	for(int i=1;i<n;i++)
	{
		arr2[i]=arr2[i-1]+arr[i];
	//	printf(" %d",arr2[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");
}



