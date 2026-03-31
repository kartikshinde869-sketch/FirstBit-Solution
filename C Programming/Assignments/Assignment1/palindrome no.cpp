#include<stdio.h>
int main()
{
	int no=757;
	int fn,ln;
	if(100<no && 1000>no)
	ln=no%10;
	fn=no/100;

	if(fn==ln){
		printf("Number is Palindrome");
	}
	else{
		printf("Number is not Palindrome");
	}
	return 0;
}