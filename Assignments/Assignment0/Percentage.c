#include<stdio.h>
int main()
{
	int Marathi=90,English=80,Physics=70,Chemistry=85,Maths=75;
	int Maximum_Marks=500;
	int Total_marks;
	float Percentage;
	Total_marks=Marathi+English+Physics+Chemistry+Maths;
	printf("Total Marks = %d\n",Total_marks);
	Percentage=(Total_marks*100)/Maximum_Marks;
	printf("Percentage = %.2f%%",Percentage);
	
	return 0;
}
