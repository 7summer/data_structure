#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}Bitree;
Bitree *creatbst();
Bitree *insertbst(Bitree *T,int key);
Bitree *find(Bitree *T,int x); //�ݹ����
Bitree *searchbst(Bitree *T,int x); //�ǵݹ����
int deletebst(Bitree **T,int key);
void freenode(Bitree *T);
Bitree *F=NULL; //���˫�׽��ָ�룬�����ɾ��ʱʹ��
int main()
{
    Bitree *T=NULL;
    Bitree *temp=NULL;
    int choice,flag;
    int key;
    do
    {
        printf("    1.��������������\n\
    2.��������\n\
    3.ɾ������\n\
    4.�ݹ��������\n\
    5.�ǵݹ��������\n\
    6.�˳�\n");
        printf("������:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                T=creatbst();
                break;
            case 2:
                printf("��������Ҫ���������:");
                scanf("%d",&key);
                T=insertbst(T,key);
                break;
            case 3:
                if(!T)
                {
                    printf("�ö�����������û������!\n");
                    break;
                }
                printf("��������Ҫɾ��������:");
                scanf("%d",&key);
                flag=deletebst(&T,key);
                if(flag) printf("ɾ��%d�ɹ�!\n",key);
                else printf("ɾ��%dʧ��\n",key);
                break;
            case 4:
                printf("��������Ҫ���ҵ�����:");
                scanf("%d",&key);
                temp=find(T,key);
                if(!temp) printf("����%dʧ��!\n",key);
                else printf("����%d�ɹ�!\n",key);
                break;
            case 5:
                printf("��������Ҫ���ҵ�����:");
                scanf("%d",&key);
                temp=searchbst(T,key);
                if(!temp) printf("����%dʧ��!\n",key);
                else printf("����%d�ɹ�!\n",key);
                break;
            case 6:
                freenode(T);
                printf("лл!\n");
                break;
            default:
                printf("�������!\n");
                break;
        }
    } while (choice!=6);
    return 0;
}
Bitree *creatbst()
{
    int key;
    Bitree *T=NULL;
    printf("������:");
    scanf("%d",&key);
    while(key!=-1) //��key==-1ʱ��ֹͣ����
    {
        T=insertbst(T,key);
        printf("������:");
        scanf("%d",&key);
    }
    return T;
}
Bitree *insertbst(Bitree *T,int key)
{
    Bitree *C,*s;
    C=find(T,key);
    if(C==NULL) //ֻ�е��Ҳ�����ʱ�򣬲Ų���
    {
        s=(Bitree*)malloc(sizeof(Bitree));
        s->data=key;
        s->left=s->right=NULL;
        if(F==NULL) T=s;
        else if(key<F->data) F->left=s;
        else F->right=s;
        printf("����ɹ�!\n");
    }
    else printf("���������Ѵ��ڸ�����!\n");
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