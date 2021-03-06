#include<stdio.h>
#include<stdlib.h>
int getDate(int y,int d)
{
	long long int dt=d;
	int i,flag=0;
	char *days[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	char *month[]={"Jan","Feb","March","April","May","June","July","August","September","October","November","December"};
	
	for(i=1900;i<y;i++)
	{
		if((i%100==0 && i%400==0) || (i%4==0 && i%100!=0))
		dt+=366;
		else
		dt+=365;
	}
	
	int day = dt%7;
	int m=1;
	
	if(y%100==0 && y%400==0)
	flag=1;
	else if(y%4==0 && y%100!=0)
	flag=1;
	
	
	while(1)
	{
		if((m==1 || m==3||m==5||m==7||m==8||m==10||m==12) && d<=31)
		break;
		else if(m==2)
		{
			if(flag==1 && d<=29)
			break;
			else if(flag==0 && d<=28)
			break;
		}
		else if((m==4 || m==6 || m==9 || m==11) && d<=30)
		break;
		
		if(m==1 || m==3||m==5||m==7||m==8||m==10||m==12)
		{
			d-=31;
			m++;
		}
		
		else if(m==2)
		{
			if(flag==1)
			d-=29;
			else
			d-=28;
			
			m++;
		}
		else
		{
			d-=30;
			m++;
		}
		
	}
	
	printf("%d %s,%s\n",d,month[m-1],days[day]);
	
	return 0;
}

int main(int argc,char *argv[])
{
	if(argc<3)
	printf("Too few arguments!\n");
	else
	{
		int y=atoi(argv[1]);
		int d=atoi(argv[2]);
		getDate(y,d);
	}
	
	return 0;
}
