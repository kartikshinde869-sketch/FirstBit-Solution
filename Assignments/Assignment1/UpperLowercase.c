#include<stdio.h>
void main()
{
	char ch;
	printf("Enter the Character :");
	scanf("%c",&ch);
	if(ch >= 'A' && ch <= 'Z'){
		printf("The Character is Uppercase");
	}
	 else if(ch >= 'a' && ch <= 'z')
	 {
	         printf("The Character is Lowercase");
		}
	     else {
	    	printf("The Character is not a Alphabet");
	   }
}