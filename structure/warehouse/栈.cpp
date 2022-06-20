#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10
typedef int ElemType;
typedef struct
{
	int top;  //ָ��ջ�пյĿռ�
	ElemType* base;
	int stacksize;
}sqstack;
void initstack(sqstack* s); //������INITSIZE�ռ��ջ
int getlen(sqstack* s);
int gettop(sqstack* s, ElemType* e); //e�����洢ջ��������
int push(sqstack* s, ElemType x); //����ѹջ����
int pop(sqstack* s, ElemType* e); //���е�ջ����,��*e���洢������������
int emptystack(sqstack* s); //�ж�ջ�Ƿ�Ϊ��
void list(sqstack* s); //���ջ����
void free_sqstack(sqstack* s); //�ͷ�ջ�Ŀռ�
int main()
{
	int choice,lenth;
	int flag;
	int e;
	sqstack s;
	s.base = NULL;
	s.top = 0;
	s.stacksize = 0;
	do
	{
		printf("	1.����ջ�ռ�\n\
	2.���ջ�ĳ���\n\
	3.��ȡջ��\n\
	4.����ѹջ����\n\
	5.���е�ջ����\n\
	6.�ж�ջ�Ƿ�Ϊ��\n\
	7.���ջ\n\
	8.�ͷ�ջ�ռ�\n");
		printf("��ѡ��:");
		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1:
				initstack(&s);
				printf("�����ɹ�!\n");
				break;
			case 2:
				lenth = getlen(&s);
				printf("��ջ�ĳ���Ϊ:%d\n", lenth);
				break;
			case 3:
				flag = gettop(&s, &e);
				if (!flag)
				{
					printf("ȡջ��ʧ��!\n");
				}
				else
				{
					printf("ջ������Ϊ:%d\n", e);
				}
				break;
			case 4:
				printf("����������:");
				scanf_s("%d", &e);
				flag = push(&s, e);
				if (!flag)
				{
					printf("ѹջʧ��!\n");
				}
				else
				{
					printf("ѹջ�ɹ�!\n");
				}
				break;
			case 5:
				flag = pop(&s, &e);
				if (!flag)
				{
					printf("��ջʧ��!\n");
				}
				else
				{
					printf("�ѵ�������:%d\n", e);
				}
				break;
			case 6:
				flag = emptystack(&s);
				if (flag)
				{
					printf("��ջΪ��!\n");
				}
				else
				{
					printf("��ջ������!\n");
				}
				break;
			case 7:
				list(&s);
				break;
			case 8:
				free_sqstack(&s);
				break;
			default:
				printf("��������ȷѡ��!\n");
				break;
		}
	} while (choice != 8);
	return 0;
}
void initstack(sqstack* s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
	s->top = 0;
	s->stacksize = INITSIZE;
}
int getlen(sqstack* s)
{
	if (s->base == NULL)
	{
		printf("ջ��û�б�����!\n");
		return 0;
	}
	return s->top;
}
int gettop(sqstack* s, ElemType* e)
{
	if (s->base == NULL)
	{
		printf("ջ��û�б�����!\n");
		return 0;
	}
	if (s->top == 0)
	{
		printf("ջ��û������!\n");
		return 0; //ȡջ��ʧ�ܣ�����0
	}
	*e = s->base[s->top - 1];
	return 1;  //ȡջ���ɹ�������1
}
int push(sqstack* s, ElemType x)
{
	if (s->base == NULL)
	{
		printf("ջ��û�б�����!\n");
		return 0;
	}
	if (s->top == s->stacksize)
	{
		s->base = (ElemType*)realloc(s->base, sizeof(ElemType)*(s->stacksize + 1));
		s->stacksize++;
	}
	s->base[s->top++] = x;
	return 1;
}
int pop(sqstack* s, ElemType* e)
{
	if (s->base == NULL)
	{
		printf("ջ��û�б�����!\n");
		return 0;
	}
	if (s->top == 0)
	{
		return 0;
	}
	*e = s->base[--s->top];
	return 1;
}
int emptystack(sqstack* s)
{
	if (s->base == NULL ||s->top == 0)
	{
		return 1;
	}
	return 0;
}
void list(sqstack* s)
{
	int i;
	if (s->base == NULL || s->top == 0)
	{
		printf("���ջʧ��!\n");
		return;
	}
	for (i = s->top - 1; i >= 0; i--)
	{
		printf("%4d", s->base[i]);
	}
	printf("\n");
}
void free_sqstack(sqstack* s)
{
	free(s->base);
	printf("�ͷųɹ�\n�������\n");
}