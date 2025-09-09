#include<stdio.h>
#include<limits.h>
void sort(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		int swapped=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp =arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=1;
			}
		}
		if(swapped==0)
		{
			break;
		}
	}
}
int main()
{
	int n;
	printf("Enter the number of elements you want to read from the file\n");
	scanf("%d",&n);
	FILE *ptr;
	ptr=fopen("efg.txt","r");
	if(ptr==NULL)
	{
		printf("Error in file reading\n");
		return 1;
	}
	int arr[n];
	for(int i=0;i<n;i++)
	{
		if(fscanf(ptr,"%d",&arr[i])!=1)
		{
			printf("Reached End of File, no numbers ahead\nExiting the program\n");
			return 1;
		}
	}
	fclose(ptr);
	sort(&arr[0],n);
	int count=0;
	int max_count=1;
	int current_count=1;
	int ans=arr[0];
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			current_count++;
		}
		else
		{
			if(current_count>1)
			{
				count++;
			}
			if(current_count>max_count)
			{
				max_count=current_count;
				ans=arr[i];
			}
			current_count=1;
		}

	}
	printf("Total number of duplicates values : %d\n",count);
	printf("The most repeating value : %d\n",ans);
}
		
