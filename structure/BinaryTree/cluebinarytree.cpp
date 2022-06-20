#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
    int ltag;
    int rtag;
}BiThrTree;
BiThrTree *pre=NULL; //����ָ�����������ǰһ�����
BiThrTree* CreatBiThrTree(); //����һ�ö�����������������
BiThrTree* InOrderThreading(BiThrTree *T); //�������������
void Inorder(BiThrTree *T); //������� �ǵݹ�
void InThreading(BiThrTree *p);
int main()
{
    BiThrTree *bt=NULL;
    bt=CreatBiThrTree();
    bt=InOrderThreading(bt);
    printf("������Ϊ:");
    Inorder(bt);
    return 0;
}
BiThrTree* CreatBiThrTree()
{
    BiThrTree *bt;
    char x;
    scanf("%c",&x);
    if( x==' ' ) bt=NULL;
    else
    {
        bt=(BiThrTree*)malloc(sizeof(BiThrTree));
        bt->data=x;
        bt->ltag=0;
        bt->rchild=0;
        bt->lchild=CreatBiThrTree();
        bt->rchild=CreatBiThrTree();
    }
    return bt;
}
BiThrTree* InOrderThreading(BiThrTree *T)
{
    BiThrTree* Thrt;
    Thrt=(BiThrTree*)malloc(sizeof(BiThrTree));
    Thrt->ltag=0;
    Thrt->rtag=1;
    Thrt->rchild=Thrt;
    if(!T) Thrt->lchild=Thrt;
    else
    {
        Thrt->lchild=T;
        pre=Thrt;
        InThreading(T);
        pre->rtag=1;
        pre->rchild=Thrt;
        Thrt->rchild=pre;
    }
    return Thrt;
}
void InThreading(BiThrTree *p)
{
    if( p )
    {
        InThreading(p->lchild); //�ݹ�����������

        if( !p->lchild )
        {
            p->ltag=1;
            p->lchild=pre;
        }
        if( !pre->rchild )
        {
            pre->rtag=1;
            pre->rchild=p;
        }
        pre=p;

        InThreading(p->rchild); //�ݹ��Һ���������
    }
}
void Inorder(BiThrTree *T)
{
    BiThrTree *p;
    p=T->lchild;
    while( p!=T )
    {
        while( p->ltag==0 )
        {
            p=p->lchild;
        }
        printf("%c", p->data);
        while( p->rtag==1 && p->rchild!=T )
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
}