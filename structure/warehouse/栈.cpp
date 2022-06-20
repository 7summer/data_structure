#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10
typedef int ElemType;
typedef struct
{
	int top;  //指向栈中空的空间
	ElemType* base;
	int stacksize;
}sqstack;
void initstack(sqstack* s); //创建有INITSIZE空间的栈
int getlen(sqstack* s);
int gettop(sqstack* s, ElemType* e); //e用来存储栈顶的数据
int push(sqstack* s, ElemType x); //进行压栈操作
int pop(sqstack* s, ElemType* e); //进行弹栈操作,用*e来存储弹出来的数据
int emptystack(sqstack* s); //判断栈是否为空
void list(sqstack* s); //输出栈操作
void free_sqstack(sqstack* s); //释放栈的空间
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
		printf("	1.创建栈空间\n\
	2.输出栈的长度\n\
	3.读取栈顶\n\
	4.进行压栈操作\n\
	5.进行弹栈操作\n\
	6.判断栈是否为空\n\
	7.输出栈\n\
	8.释放栈空间\n");
		printf("请选择:");
		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1:
				initstack(&s);
				printf("创建成功!\n");
				break;
			case 2:
				lenth = getlen(&s);
				printf("该栈的长度为:%d\n", lenth);
				break;
			case 3:
				flag = gettop(&s, &e);
				if (!flag)
				{
					printf("取栈顶失败!\n");
				}
				else
				{
					printf("栈顶数据为:%d\n", e);
				}
				break;
			case 4:
				printf("请输入数据:");
				scanf_s("%d", &e);
				flag = push(&s, e);
				if (!flag)
				{
					printf("压栈失败!\n");
				}
				else
				{
					printf("压栈成功!\n");
				}
				break;
			case 5:
				flag = pop(&s, &e);
				if (!flag)
				{
					printf("弹栈失败!\n");
				}
				else
				{
					printf("已弹出数据:%d\n", e);
				}
				break;
			case 6:
				flag = emptystack(&s);
				if (flag)
				{
					printf("该栈为空!\n");
				}
				else
				{
					printf("该栈有数据!\n");
				}
				break;
			case 7:
				list(&s);
				break;
			case 8:
				free_sqstack(&s);
				break;
			default:
				printf("请输入正确选项!\n");
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
		printf("栈还没有被创建!\n");
		return 0;
	}
	return s->top;
}
int gettop(sqstack* s, ElemType* e)
{
	if (s->base == NULL)
	{
		printf("栈还没有被创建!\n");
		return 0;
	}
	if (s->top == 0)
	{
		printf("栈还没有数据!\n");
		return 0; //取栈顶失败，返回0
	}
	*e = s->base[s->top - 1];
	return 1;  //取栈顶成功，返回1
}
int push(sqstack* s, ElemType x)
{
	if (s->base == NULL)
	{
		printf("栈还没有被创建!\n");
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
		printf("栈还没有被创建!\n");
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
		printf("输出栈失败!\n");
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
	printf("释放成功\n程序结束\n");
}