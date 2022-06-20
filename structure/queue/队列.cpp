#include <stdio.h>
#include <stdlib.h>
int MAXCSIZE=100;
typedef int ElemType;
typedef struct
{
	ElemType* base;
	int front;
	int rear;
}cqueue;
void initqueue(cqueue* cq); //��������
int getlen(cqueue* cq);
int getfront(cqueue* cq, ElemType* e); //ȡ��ͷԪ�ز���
int enqueue(cqueue* cq, ElemType x); //����в���
int outqueue(cqueue* cq, ElemType* x); //�����в���
int emptyqueue(cqueue* cq); //�ж϶���Ϊ��
void list(cqueue* cq); //�������
void free_cqueue(cqueue* cq);
int main()
{
	cqueue cq;
	cq.base = NULL;
	cq.front = cq.rear = 0;
	return 0;
}
void initqueue(cqueue* cq)
{
	cq->base = (ElemType*)malloc(sizeof(ElemType) * MAXCSIZE);
	cq->front = cq->rear = 0;
}
int getlen(cqueue* cq)
{
	return (cq->rear - cq->front + MAXCSIZE) % MAXCSIZE;
}
int getfront(cqueue* cq, ElemType* e)
{
	if (cq->front == cq->rear)
	{
		return 0;
	}
	*e = cq->base[cq->front];
	return 1;
}
int enqueue(cqueue* cq, ElemType x)
{
	if ((cq->rear + 1) % MAXCSIZE == cq->front)
	{
		return 0;
	}
	cq->base[cq->rear] = x;
	cq->rear = (cq->rear + 1) % MAXCSIZE;
	return 1;
}
int outqueue(cqueue* cq, ElemType* x)
{
	if (cq->front == cq->rear)
	{
		return 0;
	}
	*x = cq->base[cq->front];
	cq->front = (cq->front + 1) % MAXCSIZE;
	return 1;
}
int emptyqueue(cqueue* cq)
{
	if (cq->rear == cq->front)
	{
		return 1;
	}
	return 0;
}
void list(cqueue* cq)
{
	int i;
	i = cq->front;
	while (i != cq->rear)
	{
		printf("%4d", cq->base[i]);
		i = (i + 1) % MAXCSIZE;
	}
}
void free_cqueue(cqueue* cq)
{
	free(cq->base);
}