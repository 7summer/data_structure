#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 30
#define MAXCOST 1000
int lowcost[MAXVEX]; //�붥�������ıߵ�Ȩֵ
int closest[MAXVEX]; //�������·����ǰ�����
int final[MAXVEX]={0}; //�ж϶����Ƿ��Ѿ������·����
typedef struct
{
    int vertexnum,edgenum,kind; //����ͼ�Ķ�����������������
    int c[MAXVEX][MAXVEX]; //������ߵ�Ȩֵ
}AdjMatrix;
void cregraph(AdjMatrix *G);
void minimumpath(AdjMatrix *G,int start);
void show_minimumpath(AdjMatrix *G,int start); //���һ�����㵽���ж�������·��
int main()
{
    char start;
    int i,j;
    AdjMatrix G;
    cregraph(&G);
    printf("��������ʼ��:");
    scanf("%c%*c",&start);
    minimumpath(&G,start-'A');
    show_minimumpath(&G,start-'A');
    return 0;
}
void cregraph(AdjMatrix *G)
{
    int x,y,weight;
    int i,j;
    printf("������ͼ�Ķ�����������������:");
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
        printf("������ߺ�Ȩֵ:");
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
    lowcost[start]=0; //�Լ����Լ��ľ���Ϊ0
    final[start]=1; //�ѱ����뵽���·���Ķ�����Ϊ1
    closest[start]=-1; //���·�����ı�־
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