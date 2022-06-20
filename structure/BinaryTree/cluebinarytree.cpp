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
BiThrTree *pre=NULL; //用于指向中序遍历的前一个结点
BiThrTree* CreatBiThrTree(); //创造一棵二叉树，用先序序列
BiThrTree* InOrderThreading(BiThrTree *T); //中序遍历线索化
void Inorder(BiThrTree *T); //中序遍历 非递归
void InThreading(BiThrTree *p);
int main()
{
    BiThrTree *bt=NULL;
    bt=CreatBiThrTree();
    bt=InOrderThreading(bt);
    printf("输出结果为:");
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
        InThreading(p->lchild); //递归左孩子线索化

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

        InThreading(p->rchild); //递归右孩子线索化
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