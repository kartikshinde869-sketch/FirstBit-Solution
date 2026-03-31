struct Time
{
	int hr,min,sec;
};
void main()
{
	struct time t1;
	t1.hr=20;
	t1.min=320;
	t1.sec=500;
	printf(" %d - %d - %d \n",t1.hr,t1.min,t1.sec);
	t1.hr=tsec/3600;
	t1.min=tsec%3600;
	t1.sec=t1.min%60;
	t1.min=t1.min/60;
	printf(" %d - %d - %d \n",t1.hr,t1.min,t1.sec);
}