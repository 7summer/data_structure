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
		printf("	1.��������\n\
	2.��ת����\n\
	3.�������\n\
	4.�˳�\n");
		printf("��ѡ��:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("��������Ҫ���������:");
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
				printf("лл!\n");
				break;
			default:
				printf("�������!\n");
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
		printf("����û������!\n");
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
		printf("��û������!\n");
		return;
	}
	while(p!=NULL)
	{
		printf("��%dλ����:%d\n",i,p->data);
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
