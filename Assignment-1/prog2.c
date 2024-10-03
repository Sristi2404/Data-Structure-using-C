#include<stdio.h>
#include<string.h>
int main()
{
	int i,len,n,c=0;
	printf("Enter the length of string:");
	scanf("%d",&n);
	char string[n];
	printf("Enter the string:");
	scanf("%s",string);
	len=strlen(string);
	for(i=0;i<len/2;i++)
	{
		if(string[i] != string [len-i-1])
		{
			c=1;
			break;
		}
	}
	if(c==1)
		printf("Not a palindrome string\n");
	else
		printf("Palindrome String\n");
	return 0;
}
