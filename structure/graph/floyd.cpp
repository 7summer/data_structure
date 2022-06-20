#include <stdio.h>
#define MAXVEX 30
#define MAXCOST 1000
int closest[MAXVEX][MAXVEX]; //��¼���㵽����Ҫ�����ĵ㣨��̣�
typedef struct
{
    int vexternum,edgenum,kind; //ͼ�Ķ�����������������
    int lowcost[MAXVEX][MAXVEX]; //��¼���㵽�����Ȩֵ 
}AdjMatrix;
void floyd(AdjMatrix *G); //���ж��㵽���ж�������·��
int main()
{
    AdjMatrix G;
    int i,j,weight;
    char x,y;
    printf("������ͼ�Ķ�����������������:");
    scanf("%d%d%d%*c",&G.vexternum,&G.edgenum,&G.kind);
    for(i=0;i<G.vexternum;i++)
    {
        for(j=0;j<G.vexternum;j++)
        {
            if(i==j) G.lowcost[i][j]=0;
            else G.lowcost[i][j]=MAXCOST;
            closest[i][j]=j;
        }
    }
    for(i=0;i<G.edgenum;i++)
    {
        printf("������ߡ�Ȩֵ:");
        scanf("%c %c %d%*c",&x,&y,&weight);
        G.lowcost[x-'A'][y-'A']=weight;
        if(!G.kind) G.lowcost[y-'A'][x-'A']=weight;
    }
    floyd(&G);
    return 0;
}
void floyd(AdjMatrix *G)
{
    int i,j,k;
    for(i=0;i<G->vexternum;i++)
    {
        for(j=0;j<G->vexternum;j++)
        {
            for(k=0;k<G->vexternum;k++)
            {
                if(G->lowcost[j][k]>(G->lowcost[j][i]+G->lowcost[i][k]))
                {
                    G->lowcost[j][k]=G->lowcost[j][i]+G->lowcost[i][k];
                    closest[j][k]=closest[j][i];
                }
            }
        }
    }
}