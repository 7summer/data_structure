#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 30
#define MAXCOST 1000
void prim(int c[MAXVEX][MAXVEX],int n); //c存放边 n代表顶点个数
int main()
{
    int c[MAXVEX][MAXVEX];
    int n;
    int i,j;
    int lowcost;
    printf("请输入图的顶点个数:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            c[i][j]=MAXCOST;
        }
    }
    do
    {
        printf("请输入图的边:");
        scanf("%d %d",&i,&j);
        printf("请输入图的权值:");
        scanf("%d",&lowcost);
        c[i][j]=lowcost;
        c[j][i]=lowcost;
    } while (i!=0 && j!=0);
    prin(c,n);
    return 0;
}
void prim(int c[MAXVEX][MAXVEX],int n)
{
    int i,j,k,min; //min用来存放最小的权值
    int lowcost[MAXVEX],closest[MAXVEX]; //lowcost用来存放边的权值 closest判断顶点是否存在与连接的顶点
    for(i=2;i<=n;i++)
    {
        lowcost[i]=c[1][i];
        closest[i]=1; 
    }
    closest[1]=0; //将第一个顶点加入到最小生成树
    for(i=2;i<=n;i++)
    {
        min=MAXCOST;
        for(j=1;j<=n;j++) //选出最小的权值
        {
            if(closest[j]!=0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        printf("(%d,%d)\n",closest[k],k); //closest[k]输出顶点 k输出边
        closest[k]=0; //将第k个顶点加入到最小生成树
        for(j=2;j<=n;j++) 
        {
            if(closest[j]!=0 && c[k][j]<lowcost[j]) //重新对lowcost closest赋值
            {
                lowcost[j]=c[k][j];
                closest[j]=k;
            }
        }
    }
}
