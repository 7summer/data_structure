#include <stdio.h>
#include <stdlib.h>
#define LH 1 //左子树比右子树高
#define EH 0 //左右子树等高
#define RH -1 //右子树比左子树高
typedef struct node
{
    int key;
    int bf; //结点的平衡因子
    struct node *left,*right;
}Bitnode,*Bitree;
int insert(Bitree *T,int key,int *taller);
void leftbala(Bitree *T);
void rightbala(Bitree *T);
void L_Rotate(Bitree *T);
void R_Rotate(Bitree *T);
void freenode(Bitnode *T);
int main()
{
    Bitnode *T=NULL;
    int key,flag,taller;
    printf("请输入:");
    scanf("%d",&key);
    while(key!=-1)
    {
        flag=insert(&T,key,&taller);
        if(flag) printf("插入%d成功!\n",key);
        else printf("插入%d失败!\n",key);
        printf("请输入:");
        scanf("%d",&key);
    }
    freenode(T);
    return 0;
}
int insert(Bitree *T,int key,int *taller)
{
    if(!(*T))
    {
        (*T)=(Bitnode*)malloc(sizeof(Bitnode));
        (*T)->left=(*T)->right=NULL;
        (*T)->key=key;
        (*T)->bf=EH;
        *taller=1;
    }
    else
    {
        if((*T)->key==key)
        {
            *taller=0;
            return 0;
        }
        if((*T)->key>key)
        {
            if( !insert( &((*T)->left),key,taller ) )
            {
                return 0;
            }
            if(*taller)
            {
                switch((*T)->bf)
                {
                    case LH: //加入的结点在左子树，而且本身左子树就比右子树高，导致要调整平衡二叉树
                        leftbala(T);
                        *taller=0;
                        break;
                    case EH: 
                        (*T)->bf=LH; //左右子树本身是平衡的，但是在左子树加入结点后，左子树就比右子树高
                        *taller=1;
                        break;
                    case RH: //加入的结点在左子树，而且本身右子树比左子树高，平衡二叉树平衡
                        (*T)->bf=EH;
                        *taller=0;
                        break;
                }
            }
        }
        else
        {
            if( !insert( &((*T)->right),key,taller ) )
            {
                return 0;
            }
            if(*taller)
            {
                switch((*T)->bf)
                {
                    case LH:
                        (*T)->bf=EH;
                        *taller=0;
                        break;
                    case EH:
                        (*T)->bf=RH;
                        *taller=1;
                        break;
                    case RH:
                        rightbala(T);
                        *taller=0;
                        break;
                }
            }
        }
    }
    return 1;
}
void L_Rotate(Bitree *T)
{
    Bitnode *rc;
    rc=(*T)->right;
    (*T)->right=rc->left;
    rc->left=(*T);
    (*T)=rc;
}
void R_Rotate(Bitree *T)
{
    Bitnode *lc;
    lc=(*T)->left;
    (*T)->left=lc->right;
    lc->right=(*T);
    (*T)=lc;
}
void leftbala(Bitree *T)
{
    Bitnode *lc,*rd;
    lc=(*T)->left;
    switch(lc->bf)
    {
        case LH:
            (*T)->bf=lc->bf=EH;
            R_Rotate(T);
            break;
        case RH:
            rd=lc->right;
            switch(rd->bf)
            {
                case LH:
                    (*T)->bf=RH; //平衡二叉树的根结点经过平衡后，该结点所在位置右子树比左子树高
                    lc->bf=EH;
                    break;
                case EH:
                    (*T)->bf=lc->bf=EH;
                    break;
                case RH:
                    lc->bf=LH;
                    (*T)->bf=EH;
                    break;
            }
            rd->bf=EH;
            L_Rotate( &((*T)->left) );
            R_Rotate(T);
            break;
    }
}
void rightbala(Bitree *T)
{
    Bitnode *rc,*ld;
    rc=(*T)->right;
    switch(rc->bf)
    {
        case RH:
            (*T)->bf=rc->bf=EH;
            L_Rotate(T);
            break;
        case LH:
            ld=rc->left;
            switch(ld->bf)
            {
                case LH:
                    (*T)->bf=EH;
                    rc->bf=RH;
                    break;
                case RH:
                    (*T)->bf=LH;
                    rc->bf=EH;
                    break;
                case EH:
                    (*T)->bf=rc->bf=EH;
                    break;
            }
            ld->bf=EH;
            R_Rotate( &((*T)->right) );
            L_Rotate(T);
            break;
    }
}
void freenode(Bitnode *T)
{
    if(T)
    {
        if(T->left) freenode(T->left);
        if(T->right) freenode(T->right);
        free(T);
    }
}