/*Write a C program to check duplicate number in an array.*/
#include<stdio.h>
void main()
{
	int n,i,j;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter any %d elements in array:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Duplicate elements are:");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i] == arr[j])
			{
				printf("%d\n",arr[i]);
			}
		}
	}
}
