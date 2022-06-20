#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}slink;
void insert(slink *l,slink **rear,int x);
void sort(slink *l,slink **rear,int (*compare)(int a,int b));
int ascending(int a,int b); //����
int descending(int a,int b); //���� 
void show(slink *l);
void free_node(slink *l);
int main()
{
	slink *l;
	l=(slink*)malloc(sizeof(slink));
	l->next=NULL;
	int choice,x;
	slink *rear=l;
	do
	{
		printf("	1.��������\n\
	2.����\n\
	3.����\n\
	4.չʾ����\n\
	5.�˳�\n");
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
				sort(l,&rear,ascending);
				break;
			case 3:
				sort(l,&rear,descending);
				break;
			case 4:
				show(l);
				break;
			case 5:
				free_node(l);
				printf("лл!\n");
				break;
			default:
				printf("�������!\n");
				break;
		}
	}while(choice!=5);
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
void sort(slink *l,slink **rear,int (*compare)(int a,int b))
{
	if(l->next==NULL)
	{
		printf("����û������!\n");
		return;
	}
	slink *p,*q,*r,*s;
	p=l;
	while(p->next!=NULL)
	{
		q=p->next;
		r=p;
		while(q->next!=NULL)
		{
			if((*compare)(q->next->data,r->next->data))
			{
				r=q;
			}
			q=q->next;
		}
		if(p!=r)
		{
			s=r->next;
			r->next=s->next;
			s->next=p->next;
			p->next=s;
		}
		p=p->next;
	}
	p=l->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	(*rear)=p;
}
int ascending(int a,int b)
{
	return a<b;
}
int descending(int a,int b)
{
	return a>b;
}
void show(slink *l)
{
	if(l->next==NULL)
	{
		printf("����û������!\n");
		return;
	}
	int i=1;
	slink *p;
	p=l->next;
	while(p!=NULL)
	{
		printf("��%dλ����Ϊ:%d\n",i,p->data);
		p=p->next;
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
