/*Write a C program to print reverse array.*/
#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array is reverse order:\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
