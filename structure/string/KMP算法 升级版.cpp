#include <stdio.h>
int strlen(char* s);
void getnext(char* t, int next[]);
int KMPindex(char* s, char* t); //s�ַ�����t�ַ�����λ��  �����û�У��򷵻�0
int main()
{
	char s[100];
	char t[100];
	int pos, choice;
	do
	{
		printf("������Ŀ�괮:");
		scanf("%s", s);
		printf("������ģʽ��:");
		scanf("%s", t);
		pos = KMPindex(s, t);
		if (!pos)
		{
			printf("û���ҵ���ģʽ��!\n");
		}
		else
		{
			printf("λ���ڵ�%dλ\n", pos);
		}
		printf("���Ҫ����������1:");
		scanf("%d", &choice);
	} while (choice == 1);


	return 0;
}
int strlen(char* s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
int KMPindex(char* s, char* t)
{
	int next[100];
	int i, j;
	int lenth1 = strlen(s);
	int lenth2 = strlen(t);
	getnext(t, next);
	i = 0;
	j = 0;
	while (i < lenth1 && j < lenth2)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= lenth2)
	{
		return i - lenth2 + 1;
	}
	return 0;
}
void getnext(char* t, int next[])
{
	int j, k;
	int lenth = strlen(t);
	j = 0;
	k = -1;
	next[0] = -1;
	while (j < lenth)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			if (t[j] != t[k])
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}
		}
		else
		{
			k = next[k];
		}
	}
}
