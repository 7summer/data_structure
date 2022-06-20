#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;	
}slink;
void insert(slink *l,slink **rear,int x);
void turn(slink *l,slink **rear);
void show(slink *l);
void free_node(slink *l);
int main()
{
	int choice,x; 
	slink *l;
	l=(slink*)malloc(sizeof(slink));
	l->next=NULL;
	slink *rear=l;
	do
	{
		printf("	1.插入数据\n\
	2.逆转链表\n\
	3.输出链表\n\
	4.退出\n");
		printf("请选择:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("请输入需要插入的数据:");
				scanf("%d",&x);
				insert(l,&rear,x);
				break;
			case 2:
				turn(l,&rear);
				break;
			case 3:
				show(l);
				break;
			case 4:
				free_node(l);
				printf("谢谢!\n");
				break;
			default:
				printf("输入错误!\n");
				break;
		}
	}while(choice!=4);
	return 0;
}
void insert(slink *l,slink **rear,int x)
{
	slink *p;
	p=(slink*)malloc(sizeof(slink));
	p->data=x;
	p->next=NULL;
	(*rear)->next=p;
	(*rear)=p;
}
void turn(slink *l,slink **rear)
{
	if(l->next==NULL)
	{
		printf("链表还没有数据!\n");
		return;
	}
	slink *p,*q;
	(*rear)=l->next;
	p=l->next;
	l->next=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		q->next=l->next;
		l->next=q;
	}
}
void show(slink *l)
{
	int i=1; 
	slink *p=l->next;
	if(p==NULL)
	{
		printf("还没有数据!\n");
		return;
	}
	while(p!=NULL)
	{
		printf("第%d位数据:%d\n",i,p->data);
		p=p->next;
		i++;
	}
}
void free_node(slink *l)
{
	slink *p;
	while(l!=NULL)
	{
		p=l;
		l=l->next;
		free(p);
	}
}
