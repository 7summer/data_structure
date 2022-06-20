#include <stdio.h>
#include <stdlib.h>
#define MAXVER 100
typedef struct node
{
    int num;
    struct node *next;
}slink;
typedef struct
{
    struct
    {
        char vertex;
        slink *first;
        int count;
    }ve[MAXVER];
    int vex,edge,tag;
}adjust;
void cregraph(adjust *G);
void freenode(adjust *G);
void topsort(adjust *G); 
int main()
{
    adjust G;
    cregraph(&G);
    topsort(&G);
    freenode(&G);
    return 0;
}
void cregraph(adjust *G)
{
    int i;
    char x,y;
    slink *p,*q;
    printf("请输入图的顶点数、边数、图的类型:");
    scanf("%d%d%d%*c",&G->vex,&G->edge,&G->tag);
    for(i=0;i<G->vex;i++)
    {
        G->ve[i].vertex='A'+i;
        G->ve[i].count=0;
        G->ve[i].first=NULL;
    }
    printf("请输入边:\n");
    for(i=0;i<G->edge;i++)
    {
        scanf("%c%c%*c",&x,&y);
        p=(slink*)malloc(sizeof(slink));
        p->num=y-'A';
        p->next=NULL;
        G->ve[y-'A'].count++;
        if(G->ve[x-'A'].first==NULL) G->ve[x-'A'].first=p;
        else
        {
            q=G->ve[x-'A'].first;
            p->next=q;
            G->ve[x-'A'].first=p;
        }
        if(!G->tag)
        {
            p=(slink*)malloc(sizeof(slink));
            p->num=x-'A';
            G->ve[y-'A'].count++;
            if(G->ve[y-'A'].first==NULL) G->ve[y-'A'].first=p;
            else
            {
                q=G->ve[y-'A'].first;
                p->next=q;
                G->ve[y-'A'].first=p;
            }
        }
    }
}
void topsort(adjust *G)
{
    int i,j;
    int top=0;
    int n=0;
    char stack[MAXVER];
    char ch;
    slink *p;
    for(i=0;i<G->vex;i++)
    {
        if(G->ve[i].count==0) stack[top++]=G->ve[i].vertex;
    }
    while(top>0)
    {
        ch=stack[--top];
        printf("%c",ch);
        n++;
        p=G->ve[ch-'A'].first;
        while(p)
        {
            j=p->num;
            G->ve[j].count--;
            if(G->ve[j].count==0) stack[top++]=G->ve[j].vertex;
            p=p->next;
        }
    }
    if(n<G->vex) printf("该图存在环!\n");
}
void freenode(adjust *G)
{
    int i;
    slink *p,*temp;
    for(i=0;i<G->vex;i++)
    {
        p=G->ve[i].first;
        while(p)
        {
            temp=p;
            p=p->next;
            free(temp);
        }
    }
}
