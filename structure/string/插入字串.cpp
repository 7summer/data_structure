#include <stdio.h>
#include <stdlib.h>
void insert(char *s,char *t,int pos);
int main()
{
	char s[100];
	char t[10];
	int pos;
	scanf("%s",s);
	scanf("%s",t);
	scanf("%d",&pos);
	insert(s,t,pos);
	printf("%s",s);
	return 0;
}
void insert(char *s,char *t,int pos)
{
	int i=1,x=0;
	int j;
	char *p=s,*q=t;
	if(pos<1)
	{
		printf("pos²»ºÏÀí!\n");
		exit(0);
	}
	while(*p!='\0' && i<pos)
	{
		p++;
		i++;
	}
	if(*p=='\0')
	{
		exit(0);
	}
	else
	{
		while(*p!='\0')
		{
			p++;
			i++;
		}
	}
	while(*q!='\0')
	{
		q++;
		x++;
	}
	for(j=i;j>=pos;j--)
	{
		*(p+x)=*p;
		p--;
	}
	p++;
	q--;
	for(j=1;j<=x;j++)
	{
		*p-- = *q--;
	}
}
