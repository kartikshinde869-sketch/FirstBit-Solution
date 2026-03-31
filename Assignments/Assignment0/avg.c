#include<stdio.h>
void main()
{
	int no1,no2,no3,no4,no5;
	int avg;
	printf("Enter the Five numbers:");
	scanf("%d %d %d %d %d",&no1,&no2,&no3,&no4,&no5);
	avg=(no1+no2+no3+no4+no5)/5;
	printf("Avg of Five no=%d",avg);
}