typedef struct student
{
	int rollno;
	char name[20];
	int marks;
}student;
void main()
{
	struct student arr[3];
	
	printf("Enter elements:");
	for(int i=0;i<5;i++){
		scanf("%d ",&arr);
		scanf("%s ",arr);
		scanf("%d ",&arr);
	}
	
	printf("Enter student details:");
	for(int i=0;i<5;i++){
		printf("rollno=%d ",&arr);
		printf("name=%s ",arr);
		printf("marks=%d \n",&arr);
	}
	
}