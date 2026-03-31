#include<stdio.h>
void main()
{
	float F,C;
	printf(" Enter Temperature in Celsius :");
	scanf("%f",&C);
	
	F=(C*9/5)+32;
	printf("Temperature in Fahrenheit = %f\n",F);
}

