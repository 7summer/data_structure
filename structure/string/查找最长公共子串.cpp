#include <stdio.h>
void maxpubstr(char *s,char *t);
int strlen(char *str);
int main()
{
	char s[100];
	char t[100];
	printf("����������:");
	scanf("%s",s);
	printf("�������Ӵ�:");
	scanf("%s",t);
	maxpubstr(s,t);
	return 0;
}
void maxpubstr(char *s,char *t)
{
	int pos,i,j,k,len,len1;
	pos=len=i=0;
	int len_s=strlen(s);
	int len_t=strlen(t);
	while(i<len_s)
	{
		j=0;
		while(j<len_t)
		{
			if(s[i]==t[j])
			{
				len1=1;
				for(k=1;k+i<len_s&&k+j<len_t&&s[k+i]==t[k+j];k++)
				{
					len1++;
				}
				if(len1>len)
				{
					len=len1;
					pos=i;
				}
			}
			j++;
		}
		i++; 
	}
	if(len==0)
	{
		printf("û���ҵ������ִ�!\n");
		return;
	}
	printf("������ִ�Ϊ:");
	for(i=0;i<len;i++)
	{
		printf("%c",s[i+pos]);
	}
}
int strlen(char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}
