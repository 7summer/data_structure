#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int visited[MAX];
typedef struct 
{
    int vexnum,arcnum,kind; //顶点数、边数、图的种类 0代表无向图 1代表有向图
    char vex[MAX]; //存顶点信息的一维数组
    int arc[MAX][MAX]; //存边（或弧）信息的二维数组
}AdjMatrix;
void Creatjm(AdjMatrix *G);
void dfs(AdjMatrix *G,int v); //使用深度优先遍历图
void bfs(AdjMatrix *G,int v);
void dfsgraph(AdjMatrix *G);
void list(AdjMatrix *G);
int main()
{
    AdjMatrix G;
    Creatjm(&G);
    dfsgraph(&G);
    //list(&G);
    return 0;
}
void Creatjm(AdjMatrix *G)
{
    int i,j,k;
    char x,y;
    printf("请输入图的顶点数、边数、类型:");
    scanf("%d%d%d%*c",&G->vexnum,&G->arcnum,&G->kind);
    for(k=0;k<G->vexnum;k++)
    {
        G->vex[k]='A'+k;
    }
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            G->arc[i][j]=0;
        }
    }
    for(k=0;k<G->arcnum;k++)
    {
        printf("请输入边:\n");
        scanf("%c %c%*c",&x,&y);
        G->arc[x-'A'][y-'A']=1;
        if(G->kind==0) G->arc[x-'A'][y-'A']=1;
    }
}
void dfs(AdjMatrix *G,int v)
{
    int j;
    printf("%c ",G->vex[v]);
    visited[v]=1;
    for(j=0;j<G->vexnum;j++)
    {
        if(!visited[j]) dfs(G,j);
    }
}
void bfs(AdjMatrix *G,int v)
{
    int queue[MAX];
    int front,rear,i;
    int p;
    front=rear=0;
    queue[rear++]=v;
    while(front!=rear)
    {
        v=queue[front++];
        printf("%c ",G->vex[v]);
        visited[v]=1;
        for(i=0;i<G->vexnum;i++)
        {
            if(G->arc[v][i] && !visited[i])
            {
                printf("%c ",G->vex[i]);
                visited[i]=1;
            } 
        }
    }
}
void dfsgraph(AdjMatrix *G)
{
    int i,j;
    for(i=0;i<G->vexnum;i++)
    {
        if(!visited[i]) bfs(G,i);
    }
}
void list(AdjMatrix *G)
{
    int i,j;
    for(i=0;i<G->vexnum;i++)
    {
        printf("%c->",G->vex[i]);
        for(j=0;j<G->vexnum;j++)
        {
            if(G->arc[i][j]) printf("%c ",G->vex[j]);
        }
        printf("\n");
    }
}
