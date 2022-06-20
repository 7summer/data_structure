#include <stdio.h>
#define MAXE 30 //最大边数
struct edges
{
    int bv,tv,w; //存储一条边的信息 bv存储起始顶点 tv存储终止顶点 w存储权值
};
typedef struct edges edgeset[MAXE];
int seeks(int set[],int v); //set判断边与边之间是否出现环 v代表顶点的位置
void kruskal(edgeset ge,int n,int e); //ge表示的图是按权值从小到大排列的 n代表顶点个数 e代表边数
void selectsort(edgeset ge,int e);
int main()
{
    edgeset ge;
    int n,e,w;
    int i,j,k;
    printf("请输入顶点数、边数:");
    scanf("%d %d",&n,&e);
    for(i=1;i<=e;i++)
    {
        printf("请输入起始顶点和终止顶点和权值:");
        scanf("%d %d %d",&j,&k,&w);
        ge[i].bv=j;
        ge[i].tv=k;
        ge[i].w=w;
    }
    selectsort(ge,e);
    kruskal(ge,n,e);
    return 0;
}
int seeks(int set[],int v)
{
    int i=v;
    while(set[i]>0)
    {
        i=set[i];
    }
    return i;
}
void kruskal(edgeset ge,int n,int e)
{
    int set[MAXE];
    int v1,v2,i,j;
    for(i=1;i<=n;i++) set[i]=0; //一开始各个边都没有关系
    i=1; //i表示ge中的下标。初值为1
    j=1; //获取的生成树中的边数
    while(j<n && i<=e)
    {
        v1=seeks(set,ge[i].bv); //确定顶点bv所在的边集
        v2=seeks(set,ge[i].tv); //确定顶点tv所在的边集
        if(v1!=v2)
        {
            printf("(%d,%d)\n",ge[i].bv,ge[i].tv);
            set[v2]=v1;
            j++;
        }
        i++;
    }
}
void selectsort(edgeset ge,int e)
{
    struct edges temp;
    int i,j,k;
    for(i=1;i<=e-1;i++)
    {
        k=i;
        for(j=i+1;j<=e;j++)
        {
            if(ge[j].w<ge[k].w)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp=ge[i];
            ge[i]=ge[k];
            ge[k]=temp;
        }
    }
}
