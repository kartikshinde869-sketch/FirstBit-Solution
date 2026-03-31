#include<stdio.h>
void main()
{
	int a=5,b=7,temp;
	temp=a;
	a=b;
    b=temp;
	printf("%d %d",a,b);
}