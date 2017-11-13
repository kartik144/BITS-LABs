#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,p=97;
	
	char s[500];
	fgets(s,500,stdin);
	int l=strlen(s)-1;
	
	char map[8][4];
	
	for(i=0;i<8;i++)
	for(j=0;j<4;j++)
	map[i][j]='\0';
	
	for(i=0;i<8;i++)
	for(j=0;j<4;j++)
	{
		if((i==5 || i==7) && j==3)
		map[i][j]=(char)p++;
		else if(j<3)
		map[i][j]=(char)p++;
	}
	
	int prev=-1;
	char ch;
	
	for(i=0;i<l;i++)
	{
		ch=s[i];
		
		if(ch==' ')
		{
			printf("0");
			prev=-1;
		}
		else
		{
			j=0;
			int up=2;
			
			while(1)
			{
				if(ch>=map[j][0] && ch<=map[j][up])
				break;
				else
				{
					j++;
				
					if(j==5 || j==7)
					up=3;
					else
					up=2;
				
					continue;
				}
			}
			
			if(j==prev)
			printf(" ");
			
			k=0;
			
			while(1){
			if(map[j][k]==ch)
			{
				printf("%d",j+2);
				break;
			}
			
			printf("%d",j+2);
			k++;
			}
			
			prev=j;
		}
		 
	}
	
	printf("\n");
	
	return 0;
}
