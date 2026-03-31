#include<stdio.h>
void main()
{
	int min=127;
	int hrs,remmin;
	hrs=min/60;
	remmin=min%60;
	printf("hrs : %d\nremmin : %d\n",hrs,remmin);
}