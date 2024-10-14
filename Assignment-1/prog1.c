/*Write a C program to print an array.*/
#include<stdio.h>
int main()
{
	int i,n;
	printf("Enter the value of n:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the integers:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The array is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
