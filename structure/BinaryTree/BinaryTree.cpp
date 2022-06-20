#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;      //数据域的类型
typedef struct node
{
	ElemType data;             //数据域
	struct node *lc;             //左孩指针
	struct node *rc;             //右孩指针
}BitTree;
BitTree *CreBitTree(); //采用先序遍历序列输入
void PreOrder(BitTree *bt); //输出二叉树的先序遍历
void InOrder(BitTree *bt); //输出二叉树的中序遍历
void PostOrder(BitTree *bt); //输出二叉树的后序遍历
void countjd(BitTree* bt,int *sum); //统计二叉树结点个数，并用sum记录
int hightree(BitTree* bt); //计算二叉树的高度
void leafcount(BitTree* bt, int* jd); //统计叶子结点的个数
void onecount(BitTree* bt, int* jd); //统计单孩子结点的个数
void freeBitTree(BitTree *bt);
int max_size=100; //栈、队列存储空间的最大值 
int main()
{
	BitTree *bt=NULL;
	int choice; //用来记录用户的选择
	int sum; //用来记录结点数
	do
	{
		printf("	1.建立二叉树\n\
	2.先序遍历\n\
	3.中序遍历\n\
	4.后序遍历\n\
	5.统计二叉树结点个数\n\
	6.计算二叉树的高度\n\
	7.统计叶子结点的个数\n\
	8.统计单孩子结点的个数\n\
	9.退出\n");
		printf("请选择:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getchar();
				printf("输入%%为空\n");
				printf("请根据先序遍历序列输入:");
				bt=CreBitTree();
				printf("输入成功\n");
				break;
			case 2:
				printf("二叉树的先序遍历:");
				PreOrder(bt);
				printf("\n");
				break;
			case 3:
				printf("二叉树的中序遍历:");
				InOrder(bt);
				printf("\n");
				break;
			case 4:
				printf("二叉树的后序遍历:");
				PostOrder(bt);
				printf("\n");
				break;
			case 5:
				countjd(bt,&sum);
				printf("二叉树的结点个数为:%d\n",sum);
				break;
			case 6:
				sum=hightree(bt);
				printf("二叉树的高度为:%d\n",sum);
				break;
			case 7:
				leafcount(bt,&sum);
				printf("二叉树的叶子结点个数为:%d\n",sum);
				break;
			case 8:
				onecount(bt,&sum);
				printf("二叉树的单孩子结点个数为:%d\n",sum);
				break;
			case 9:
				freeBitTree(bt);
				printf("谢谢!\n");
				break;
			default:
				printf("输入错误!\n");
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
	BitTree **s; //用来存储二叉树的结点 用栈的知识来进行先序遍历
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
			if(p->rc) s[top++]=p->rc; //非空的右指针进栈
			p=p->lc; //沿着左指针访问，直到左指针为空为止
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
	BitTree **s,*p; //用来存储二叉树的结点 用队列的知识来计算二叉树的结点个数
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