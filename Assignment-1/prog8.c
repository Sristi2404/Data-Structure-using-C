/*Write a C program to check the sum of all elements of an array.*/
#include<stdio.h>
int main()
{
	int sum=0,n,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:");
        for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	printf("Sum:%d\n",sum);
	return 0;
}	
