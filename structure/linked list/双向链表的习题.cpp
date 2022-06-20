#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	struct node *prior;
	int freq;
	int data;
	struct node *next;	
}dlink;
void insert(dlink *h,dlink **rear,int x);
int locate(dlink *h,dlink **rear,int x);
void show(dlink *h);
void free_node(dlink *h);
int main()
{
	dlink *h;
	dlink *rear;
	int choice,x;
	int flag;
	h=(dlink*)malloc(sizeof(dlink));
	h->next=NULL;
	h->prior=NULL;
	rear=h;
	do
	{
		printf("	1.插入数据\n\
	2.定位数据\n\
	3.展示双向链表\n\
	4.退出\n");
		printf("请选择:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("请输入需要插入的数据:");
				scanf("%d",&x);
				insert(h,&rear,x);
				break;
			case 2:
				printf("请输入需要定位的数据:");
				scanf("%d",&x);
				flag=locate(h,&rear,x);
				if(flag)
				{
					printf("该链表有该数据!\n");
				}
				else
				{
					printf("定位失败!\n");
				}
				break;
			case 3:
				show(h);
				break;
			case 4:
				free_node(h);
				printf("谢谢!\n");
				break;
			default:
				printf("输入错误!\n");
				break;
		}
	}while(choice!=4);
	return 0;
}
void insert(dlink *h,dlink **rear,int x)
{
	dlink *p;
	p=(dlink*)malloc(sizeof(dlink));
	p->freq=0;
	p->data=x;
	p->next=NULL;
	p->prior=(*rear);
	(*rear)->next=p;
	(*rear)=p;
}
int locate(dlink *h,dlink **rear,int x)
{
	dlink *p,*q;
	p=h->next;
	while(p!=NULL && p->data!=x)
	{
		p=p->next;
	}
	if(!p) return 0;
	p->freq++;
	q=p->prior;
	while(q!=h&&p->freq>q->freq)
	{
		p->prior=q->prior;
		p->prior->next=p;
		q->next=p->next;
		if(q->next!=NULL)
		{
			q->next->prior=q;
		}
		p->next=q;
		q->prior=p;
		q=p->prior;
	}
	p=h->next;
	while(p->next!=NULL)
	{
		p=p->next;	
	} 
	(*rear)=p;
	return 1;
}
void show(dlink *h)
{
	if(h->next==NULL)
	{
		printf("双向链表还没有数据!\n");
		return;
	}
	dlink *p;
	p=h->next;
	int i=1;
	while(p!=NULL)
	{
		printf("第%d个数据为%d\n",i,p->data);
		p=p->next;
	}
}
void free_node(dlink *h)
{
	dlink *p;
	while(h!=NULL)
	{
		p=h;
		h=h->next;
		free(p);
	}
}
