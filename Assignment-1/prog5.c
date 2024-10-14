/*Write a C program to print the largest and second largest element of the array.*/
#include<stdio.h>
int main()
{
	int n,l1,l2,i;
	printf("Enter number of elements you want in array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	l1=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]>l1)
		{
			l1=arr[i];
		}
	}
	l2=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i] > l2 && arr[i] < l1)
		{
			l2=arr[i];
		}
	}
	printf("First and second largest number is %d and %d.\n",l1,l2);
	return 0;
}
