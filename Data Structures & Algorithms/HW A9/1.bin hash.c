#include<stdio.h>
#include<string.h>

void removeDups(char s[100])
{
	int hash[256];
	int l=strlen(s),i;
	
	for(i=0;i<256;i++)
	hash[i]=0;
	
	for(i=0;i<l;i++)
	{
		if(hash[(int)s[i]]==1)
		s[i]='\0';
		else
		hash[(int)s[i]]++;
	}
	return;
	
}

int main()
{
	char s[100];
	scanf("%s",s);
	int l=strlen(s);
	removeDups(s);
	
	int i;
	for(i=0;i<l;i++)
	if(s[i]!='\0')
	printf("%c",s[i]);
	
	printf("\n");
	
	return 0;
}
