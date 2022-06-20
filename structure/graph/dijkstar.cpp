#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 30
#define MAXCOST 1000
int lowcost[MAXVEX]; //与顶点相连的边的权值
int closest[MAXVEX]; //储存最短路径的前驱结点
int final[MAXVEX]={0}; //判断顶点是否已经在最短路径中
typedef struct
{
    int vertexnum,edgenum,kind; //储存图的顶点数、边数、类型
    int c[MAXVEX][MAXVEX]; //储存各边的权值
}AdjMatrix;
void cregraph(AdjMatrix *G);
void minimumpath(AdjMatrix *G,int start);
void show_minimumpath(AdjMatrix *G,int start); //求出一个顶点到所有顶点的最短路径
int main()
{
    char start;
    int i,j;
    AdjMatrix G;
    cregraph(&G);
    printf("请输入起始点:");
    scanf("%c%*c",&start);
    minimumpath(&G,start-'A');
    show_minimumpath(&G,start-'A');
    return 0;
}
void cregraph(AdjMatrix *G)
{
    int x,y,weight;
    int i,j;
    printf("请输入图的顶点数、边数、类型:");
    scanf("%d%d%d%*c",&G->vertexnum,&G->edgenum,&G->kind);
    for(i=0;i<G->vertexnum;i++)
    {
        for(j=0;j<G->vertexnum;j++)
        {
            if(i==j) G->c[i][j]=0;
            else G->c[i][j]=MAXCOST;
        }
    }
    for(i=0;i<G->edgenum;i++)
    {
        printf("请输入边和权值:");
        scanf("%c %c %d%*c",&x,&y,&weight);
        G->c[x-'A'][y-'A']=weight;
        if(!G->kind) G->c[y-'A'][x-'A']=weight; 
    }
}
void minimumpath(AdjMatrix *G,int start)
{
    int i,j,k,min;
    for(i=0;i<G->vertexnum;i++)
    {
        lowcost[i]=G->c[start][i];
    }
    lowcost[start]=0; //自己到自己的距离为0
    final[start]=1; //已被加入到最短路径的顶点置为1
    closest[start]=-1; //最短路径起点的标志
    for(i=1;i<G->vertexnum;i++)
    {
        min=MAXCOST;
        for(j=0;j<G->vertexnum;j++)
        {
            if(!final[j] && lowcost[j]<min)
            {
                k=j;
                min=lowcost[j];
            }
        }
        final[k]=1;
        for(j=0;j<G->vertexnum;j++)
        {
            if(!final[j] && (min+G->c[k][j])<lowcost[j])
            {
                lowcost[j]=min+G->c[k][j];
                closest[j]=k;
            }
        }
    }
}
void show_minimumpath(AdjMatrix *G,int start)
{
    int i=0;
    for(i=0;i<G->vertexnum;i++)
    {
        if(i!=start) printf("%c->%c\n",closest[i]+'A',i+'A');
    }
}