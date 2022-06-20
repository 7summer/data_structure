#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10
typedef struct
{
	int top;  //ָ��ջ�пյĿռ�
	char* base;
	int stacksize;
}sqstack;
void conversion(sqstack *s,int m, int n);
void initstack(sqstack* s);
int push(sqstack* s, char x);
void list(sqstack* s);
int main()
{
	int m, n;
	int choice;
	sqstack s;
	initstack(&s);
	do
	{
		s.top=0;
		printf("������ʮ��������");
		scanf("%d", &m);
		printf("Ҫת��Ϊ���ٽ��ƣ�");
		scanf("%d", &n);
		conversion(&s, m, n);
		printf("��Ҫ����������1:");
		scanf("%d",&choice);		
	}while(choice==1);
	free(s.base);
	return 0;
}
void conversion(sqstack *s,int m, int n)
{
	int temp = m;
	while (temp != 0)
	{
		if(n==16 && temp%n>10)
		{
			push(s, temp%n+54);
		}
		push(s, temp % n + '0');
		temp /= n;
	}
	printf("%d��%d������Ϊ:",m,n);
	list(s);
}
void initstack(sqstack* s)
{
	s->base = (char*)malloc(sizeof(char) * INITSIZE);
	s->top = 0;
	s->stacksize = INITSIZE;
}
int push(sqstack* s, char x)
{
	if (s->top == s->stacksize)
	{
		s->base = (char*)realloc(s->base, sizeof(char)*(s->stacksize + 1));
		s->stacksize++;
	}
	s->base[s->top++] = x;
	return 1;
}
void list(sqstack* s)
{
	int i;
	for (i = s->top - 1; i >= 0; i--)
	{
		printf("%c", s->base[i]);
	}
	printf("\n");
}
