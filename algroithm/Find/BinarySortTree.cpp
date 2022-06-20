#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}Bitree;
Bitree *creatbst();
Bitree *insertbst(Bitree *T,int key);
Bitree *find(Bitree *T,int x); //递归查找
Bitree *searchbst(Bitree *T,int x); //非递归查找
int deletebst(Bitree **T,int key);
void freenode(Bitree *T);
Bitree *F=NULL; //存放双亲结点指针，插入和删除时使用
int main()
{
    Bitree *T=NULL;
    Bitree *temp=NULL;
    int choice,flag;
    int key;
    do
    {
        printf("    1.创建二叉排序树\n\
    2.插入数据\n\
    3.删除数据\n\
    4.递归查找数据\n\
    5.非递归查找数据\n\
    6.退出\n");
        printf("请输入:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                T=creatbst();
                break;
            case 2:
                printf("请输入需要插入的数据:");
                scanf("%d",&key);
                T=insertbst(T,key);
                break;
            case 3:
                if(!T)
                {
                    printf("该二叉排序树还没有数据!\n");
                    break;
                }
                printf("请输入需要删除的数据:");
                scanf("%d",&key);
                flag=deletebst(&T,key);
                if(flag) printf("删除%d成功!\n",key);
                else printf("删除%d失败\n",key);
                break;
            case 4:
                printf("请输入需要查找的数据:");
                scanf("%d",&key);
                temp=find(T,key);
                if(!temp) printf("查找%d失败!\n",key);
                else printf("查找%d成功!\n",key);
                break;
            case 5:
                printf("请输入需要查找的数据:");
                scanf("%d",&key);
                temp=searchbst(T,key);
                if(!temp) printf("查找%d失败!\n",key);
                else printf("查找%d成功!\n",key);
                break;
            case 6:
                freenode(T);
                printf("谢谢!\n");
                break;
            default:
                printf("输入错误!\n");
                break;
        }
    } while (choice!=6);
    return 0;
}
Bitree *creatbst()
{
    int key;
    Bitree *T=NULL;
    printf("请输入:");
    scanf("%d",&key);
    while(key!=-1) //当key==-1时，停止输入
    {
        T=insertbst(T,key);
        printf("请输入:");
        scanf("%d",&key);
    }
    return T;
}
Bitree *insertbst(Bitree *T,int key)
{
    Bitree *C,*s;
    C=find(T,key);
    if(C==NULL) //只有当找不到的时候，才插入
    {
        s=(Bitree*)malloc(sizeof(Bitree));
        s->data=key;
        s->left=s->right=NULL;
        if(F==NULL) T=s;
        else if(key<F->data) F->left=s;
        else F->right=s;
        printf("插入成功!\n");
    }
    else printf("二叉树中已存在该数据!\n");
    return T;
}
Bitree *find(Bitree *T,int x)
{
    Bitree *temp;
    if(T==NULL) return NULL;
    if(T->data==x) return T;
    else
    {
        F=T;
        if(T->data>x) temp=find(T->left,x);
        else temp=find(T->right,x);
    }
    return temp;
}
Bitree *searchbst(Bitree *T,int x)
{
    Bitree *C=NULL;
    while(T!=NULL)
    {
        if(T->data==x)
        {
            C=T;
            break;
        }
        else if(x<T->data)
        {
            F=T;
            T=T->left;
        }
        else
        {
            F=T;
            T=T->right;
        }
    }
    return C;
}
int deletebst(Bitree **T,int key)
{
    Bitree *p,*s=NULL,*q;
    p=find(*T,key);
    if(!q) return 0;
    if(p->left==NULL)
    {
        q=p;
        p=p->right;
    }
    else if(p->right==NULL)
    {
        q=p;
        p=p->left;
    }
    else
    {
        q=p;
        s=p->left;
        while(s->right!=NULL)
        {
            q=s;
            s=s->right;
        }
        if(q!=p) q->right=s->left;
        else q->left=s->left;
        q=s;
        p->data=s->data;
    }
    if(F==NULL) (*T)=p;
    else if(q!=s)
    {
        if(key<F->data) F->left=p;
        else F->right=p;
    }
    free(q);
    return 1;
}
void freenode(Bitree *T)
{
    if(T)
    {
        if(T->left) freenode(T->left);
        if(T->right) freenode(T->right);
        free(T);
    }
}