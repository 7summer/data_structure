#include <stdio.h>
#include <stdlib.h>
int MAXSIZE;
typedef int ElemType;
typedef struct
{
	ElemType data;
	int cur;
}stalink;
void initlist(stalink space[]); //建立空的静态链表
int allocnode(stalink space[]); //获取空的节点
void freenode(stalink space[], int i); //回收结点
int crestalink(stalink space[], int n); //建立一个含有n个节点的静态链表 返回值为头结点
int getlen(stalink space[], int head);
int getelem(stalink space[], int head, int i, ElemType* e); //取出第i个节点的数据
int locate(stalink space[], int head, ElemType x); //确定静态链表中第一个值为x的结点的位置
int insert(stalink space[], int head, int i, ElemType x);
int Delete(stalink space[], int head, int i, ElemType* e);
void list(stalink space[], int head);
int main()
{
	printf("需要创建多少空间的静态链表:");
	scanf("%d", &MAXSIZE);
	stalink* space;
	space = (stalink*)malloc(sizeof(stalink) * MAXSIZE);
	return 0;
}
void initlist(stalink space[])
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE-1].cur = 0;
}
int allocnode(stalink space[])
{
	int i;
	i = space[0].cur;
	if (i == 0) return 0;
	space[0].cur = space[i].cur;
	return i;
}
void freenode(stalink space[], int i)
{
	space[i].cur = space[0].cur;
	space[0].cur = i;
}
int creatalink(stalink space[], int n)
{
	int head, k, s, i;
	k = head = allocnode(space);
	for (i = 1; i <= n; i++)
	{
		s = allocnode(space);
		printf("请输入第%d个数据:", i);
		scanf("%d", &space[s].data);
		space[k].cur = s;
		k = s;
	}
	return head;
}
int getlen(stalink space[], int head)
{
	int i, k;
	i = 0;
	k = space[head].cur;
	while (k != 0)
	{
		i++;
		k = space[k].cur;
	}
	return i;
}
int getelem(stalink space[], int head, int i, ElemType* e)
{
	int j, k;
	if (i < 1) return 0;
	j = 0;
	k = head;
	while (k != 0 && j < i)
	{
		j++;
		k = space[k].cur;
	}
	if (k == 0) return 0;
	*e = space[k].data;
	return 1;
}
int locate(stalink space[], int head, ElemType x)
{
	int k;
	k = space[head].cur;
	while (k != 0 && space[k].data != x)
	{
		k = space[k].cur;
	}
	return k; //不存在则放回0,否则返回下标k
}
int insert(stalink space[], int head, int i, ElemType x)
{
	int j, k,m;
	if (i < 1) return 0;
	k = head;
	j = 0;
	while (k != 0 && j < i - 1)
	{
		k = space[k].cur;
		j++;
	}
	if (k == 0) return 0;
	m = allocnode(space);
	if (m != 0)
	{
		space[m].data = x;
		space[m].cur = space[k].cur;
		space[k].cur = m;
		return 1;
	}
	else
	{
		return 0;
	}
}
int Delete(stalink space[], int head, int i, ElemType* e)
{
	int j, k, m;
	if (i < 1) return 0;
	k = head;
	j = 0;
	while (k != 0 && j < i - 1)
	{
		j++;
		k = space[k].cur;
	}
	if (k == 0) return 0;
	m = space[k].cur;
	space[k].cur = space[m].cur;
	*e = space[m].data;
	freenode(space, i);
}
void list(stalink space[], int head)
{
	int i;
	i = space[head].cur;
	while (i != 0)
	{
		printf("%d", space[i].data);
		i = space[i].cur;
	}
	printf("\n");
}