#include<stdio.h>
#include<limits.h>
int main()
{
	int n;
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL)
	{
		printf("Error while readint the file\n");
		return 1;
	}
	fscanf(fp,"%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		if(fscanf(fp,"%d",&arr[i])!=1)
		{
			printf("Reached End of File,no numbers ahead\nExiting the program");
			fclose(fp);
			return 1;
		}
	}
	int large=INT_MIN;
	int slarge=INT_MIN;	//Second Largest 
	int small=INT_MAX;	
	int ssmall=INT_MAX;	//Second Smallest
	for(int i=0;i<n;i++)
	{
		if(arr[i]>large)
		{
			slarge=large;
			large=arr[i];	
		}
		else if(arr[i]<large&&arr[i]>slarge)
		{
			slarge=arr[i];
		}
		if(arr[i]<small)
		{
			ssmall=small;
			small=arr[i];
		}
		else if(arr[i]>small&&arr[i]<ssmall)
		{
			ssmall=arr[i];
		}
	}
	printf("Second largest is %d\n",slarge);
	printf("Second smallest is %d\n",ssmall);
}



