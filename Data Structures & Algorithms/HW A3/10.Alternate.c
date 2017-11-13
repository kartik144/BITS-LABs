#include<stdio.h>
#include<string.h>

int getLines(char *s)
{
	FILE *fp=fopen(s,"r");
	char ch=getc(fp);
	int c=0;
	
	while(ch!=EOF)
	{
		if(ch=='\n')
		c++;
		
		ch=getc(fp);
	}
	
	return c;
}

int main(int argc,char *argv[])
{
	FILE *f1=fopen(argv[1],"r");
	int l=getLines(argv[1]);
	int i;
	char s[l][1000],buff[1000];
	
	for(i=0;i<l;i++)
		fgets(s[i],1000,f1);
		
	for(i=0;i<l;i++)
	printf("%s",s[i])
;	
	for(i=0;i<=l/2;i+=2)
	{
		//if(i==l/2)
		strcpy(buff,s[i]);
		strcpy(s[i],s[i+1]);
		strcpy(s[i+1],buff);
	}
	
	//f1.close();
	
	FILE *f2=fopen(argv[1],"w");

	for(i=0;i<l;i++)
	fprintf(f2,"%s",s[i]);
	
	//f2.close();
	
	return 0;
}
