#include <stdio.h>
#include <stdlib.h>
#define MAXVER 100
int visited[MAXVER];
typedef struct node 
{
    int num;
    struct node *next;
}slink;
typedef struct
{
    struct
    {
        char vertex; //��������
        slink *first; //ָ��ĵ�
    }ve[MAXVER];
    int vex,edge,tag; //��Ŷ�������������ͼ������
}adjust;
void cregraph(adjust *G);
void dfs(adjust *G,int v); //�����������
void dfsgraph(adjust *G);
void bfs(adjust *G,int v); //�����������
void list(adjust *G);
void freenode(adjust *G);
int main()
{
    adjust G;
    cregraph(&G);
    dfsgraph(&G);
    printf("\n");
    list(&G);
    freenode(&G);
    return 0;
}
void cregraph(adjust *G)
{
    int i;
    char x,y;
    slink *p,*q;
    printf("������ͼ�Ķ��㡢����������:");
    scanf("%d%d%d%*c",&G->vex,&G->edge,&G->tag);
    for(i=0;i<G->vex;i++)
    {
        G->ve[i].vertex='A'+i;
        G->ve[i].first=NULL;
    }
    printf("�������:\n");
    for(i=0;i<G->edge;i++)
    {
        scanf("%c%c%*c",&x,&y);
        p=(slink*)malloc(sizeof(slink));
        p->num=y-'A';
        p->next=NULL;
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
            p->next=NULL;
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
void dfs(adjust *G,int v)
{
    slink *p;
    printf("%c ",G->ve[v].vertex);
    visited[v]=1;
    p=G->ve[v].first;
    while(p)
    {
        if(!visited[p->num]) dfs(G,p->num);
        p=p->next;
    }
}
void dfsgraph(adjust *G)
{
    int i;
    for(i=0;i<G->vex;i++)
    {
        if(!visited[i]) bfs(G,i);
    }
}
void bfs(adjust *G,int v)
{
    int queue[MAXVER],front,rear,i;
    slink *p;
    front=rear=0;
    queue[rear++]=v;
    while(front!=rear)
    {
        v=queue[front++];
        printf("%c ",G->ve[v].vertex);
        visited[v]=1;
        p=G->ve[v].first;
        while(p)
        {
            for(i=0;i<rear;i++)
            {
                if(p->num==queue[i]) break;
            }
            if(i>=rear) queue[rear++]=p->num;
            p=p->next;
        }
    }
}
void list(adjust *G)
{
    slink *p;
    int i;
    for(i=0;i<G->vex;i++)
    {
        p=G->ve[i].first;
        printf("%c->",G->ve[i].vertex);
        while(p)
        {
            printf("%c ",G->ve[p->num].vertex);
            p=p->next;
        }
        printf("\n");
    }
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
