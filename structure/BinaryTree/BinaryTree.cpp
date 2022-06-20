#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;      //�����������
typedef struct node
{
	ElemType data;             //������
	struct node *lc;             //��ָ��
	struct node *rc;             //�Һ�ָ��
}BitTree;
BitTree *CreBitTree(); //�������������������
void PreOrder(BitTree *bt); //������������������
void InOrder(BitTree *bt); //������������������
void PostOrder(BitTree *bt); //����������ĺ������
void countjd(BitTree* bt,int *sum); //ͳ�ƶ�����������������sum��¼
int hightree(BitTree* bt); //����������ĸ߶�
void leafcount(BitTree* bt, int* jd); //ͳ��Ҷ�ӽ��ĸ���
void onecount(BitTree* bt, int* jd); //ͳ�Ƶ����ӽ��ĸ���
void freeBitTree(BitTree *bt);
int max_size=100; //ջ�����д洢�ռ�����ֵ 
int main()
{
	BitTree *bt=NULL;
	int choice; //������¼�û���ѡ��
	int sum; //������¼�����
	do
	{
		printf("	1.����������\n\
	2.�������\n\
	3.�������\n\
	4.�������\n\
	5.ͳ�ƶ�����������\n\
	6.����������ĸ߶�\n\
	7.ͳ��Ҷ�ӽ��ĸ���\n\
	8.ͳ�Ƶ����ӽ��ĸ���\n\
	9.�˳�\n");
		printf("��ѡ��:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getchar();
				printf("����%%Ϊ��\n");
				printf("��������������������:");
				bt=CreBitTree();
				printf("����ɹ�\n");
				break;
			case 2:
				printf("���������������:");
				PreOrder(bt);
				printf("\n");
				break;
			case 3:
				printf("���������������:");
				InOrder(bt);
				printf("\n");
				break;
			case 4:
				printf("�������ĺ������:");
				PostOrder(bt);
				printf("\n");
				break;
			case 5:
				countjd(bt,&sum);
				printf("�������Ľ�����Ϊ:%d\n",sum);
				break;
			case 6:
				sum=hightree(bt);
				printf("�������ĸ߶�Ϊ:%d\n",sum);
				break;
			case 7:
				leafcount(bt,&sum);
				printf("��������Ҷ�ӽ�����Ϊ:%d\n",sum);
				break;
			case 8:
				onecount(bt,&sum);
				printf("�������ĵ����ӽ�����Ϊ:%d\n",sum);
				break;
			case 9:
				freeBitTree(bt);
				printf("лл!\n");
				break;
			default:
				printf("�������!\n");
				break;
		}
	} while (choice!=9);
	
	return 0;
}
BitTree *CreBitTree()
{
	BitTree *bt;
	ElemType x;
	scanf("%c",&x);
	if(x=='%') bt=NULL;
	else
	{
		bt=(BitTree*)malloc(sizeof(BitTree));
		bt->data=x;
		bt->lc=CreBitTree();
		bt->rc=CreBitTree();
	}
	return bt;
}
void PreOrder(BitTree *bt)
{
	int top=0;
	BitTree **s; //�����洢�������Ľ�� ��ջ��֪ʶ�������������
	BitTree *p;
	s=(BitTree**)malloc(sizeof(BitTree*)*max_size);
	if(bt) s[top++]=bt;
	else return;
	while(top)
	{
		p=s[--top];
		while(p) 
		{
			printf("%c",p->data);
			if(p->rc) s[top++]=p->rc; //�ǿյ���ָ���ջ
			p=p->lc; //������ָ����ʣ�ֱ����ָ��Ϊ��Ϊֹ
		}
	}
}
void InOrder(BitTree *bt)
{
	if(bt)
	{
		InOrder(bt->lc);
		printf("%c",bt->data);
		InOrder(bt->rc);
	}
}
void PostOrder(BitTree *bt)
{
	if(bt)
	{
		PostOrder(bt->lc);
		PostOrder(bt->rc);
		printf("%c",bt->data);
	}
}
void countjd(BitTree* bt,int *sum)
{
	BitTree **s,*p; //�����洢�������Ľ�� �ö��е�֪ʶ������������Ľ�����
	s=(BitTree**)malloc(sizeof(BitTree*)*max_size);
	int front,rear;
	front=rear=0;
	(*sum)=0;
	if(bt)
	{
		s[rear]=bt;
		rear=(rear+1)%max_size;	
	}
	while(front!=rear)
	{
		p=s[front];
		front=(front+1)%max_size;
		(*sum)++;
		if(p->lc)
		{
			s[rear]=p->lc;
			rear=(rear+1)%max_size;
		}
		if(p->rc)
		{
			s[rear]=p->rc;
			rear=(rear+1)%max_size;
		}
	}
	free(s);
}
int hightree(BitTree* bt)
{
	int h,h1,h2;
	if(!bt) h=0;
	else
	{
		h1=hightree(bt->lc);
		h2=hightree(bt->rc);
		h=(h1>h2?h1:h2)+1;
	}
	return h;
}
void leafcount(BitTree* bt, int* jd)
{
	BitTree **s,*p;
	int top=0;
	s=(BitTree**)malloc(sizeof(BitTree*)*max_size);
	(*jd)=0;
	if(bt) s[top++]=bt;
	while(top)
	{
		p=s[--top];
		if(p->lc==NULL && p->rc==NULL)
		{
			(*jd)++;
		}
		if(p->lc) s[top++]=p->lc;
		if(p->rc) s[top++]=p->rc;
	}
	free(s);
}
void onecount(BitTree* bt, int* jd)
{
	BitTree **s,*p;
	int top=0;
	s=(BitTree**)malloc(sizeof(BitTree*)*max_size);
	(*jd)=0;
	if(bt) s[top++]=bt;
	while(top)
	{
		p=s[--top];
		if(p->lc==NULL ^ p->rc==NULL)
		{
			(*jd)++;
		}
		if(p->lc) s[top++]=p->lc;
		if(p->rc) s[top++]=p->rc;
	}
}
void freeBitTree(BitTree *bt)
{
	if(bt)
	{
		freeBitTree(bt->lc);
		freeBitTree(bt->rc);
		free(bt);
	}
}