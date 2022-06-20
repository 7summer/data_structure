#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 30
#define ERROR 0 //定义枚举类型
#define OK 1 //定义枚举类型
typedef int STATUS;
typedef struct edgenode
{
    int adjvex; //邻接点域
    int weight; //权值
    struct edgenode *next;
}edgenode;
typedef struct vertexnode
{
    int in; //入度
    char vex; //顶点名称
    edgenode *first; //连接点
}vertex,AdjList[MAXVEX];
typedef struct
{
    AdjList adjlist;
    int numvertexes; //顶点数
    int numedges; //边数
}GraphAdjList;
int *etv,*ltv; //(顶点)事件最早开始时间 最晚发生时间
char *stack; //储存拓扑排序序列
int top=0; //用于stack
void CreateGraphAdjList(GraphAdjList *G);
STATUS TopologicalSort(GraphAdjList *G); //拓扑排序
void CriticalPath(GraphAdjList *G);
int main()
{
    GraphAdjList G;
    CreateGraphAdjList(&G);
    CriticalPath(&G);
    free(etv);
    free(ltv);
    free(stack);
}
void CreateGraphAdjList(GraphAdjList *G)
{
    int i;
    char x,y;
    int weight;
    edgenode *e,*p;
    printf("请输入顶点数、边数:");
    scanf("%d %d%*c",&G->numvertexes,&G->numedges);
    for(i=0;i<G->numvertexes;i++)
    {
        G->adjlist[i].vex='A'+i;
        G->adjlist[i].first=NULL;
        G->adjlist[i].in=0;
    }
    for(i=0;i<G->numedges;i++)
    {
        printf("请输入边、权值:");
        scanf("%c %c %d%*c",&x,&y,&weight);
        G->adjlist[y-'A'].in++;
        e=(edgenode*)malloc(sizeof(edgenode));
        e->adjvex=y-'A';
        e->weight=weight;
        p=G->adjlist[x-'A'].first;
        e->next=p;
        G->adjlist[x-'A'].first=e;
    }
}
STATUS TopologicalSort(GraphAdjList *G)
{
    edgenode *e;
    int i,j;
    char gettop;
    int top2=0;
    int count=0; //判断图是否出现环
    char *stack2; //用于拓扑排序
    stack=(char*)malloc(sizeof(char)*G->numvertexes);
    stack2=(char*)malloc(sizeof(char)*G->numvertexes);
    etv=(int*)malloc(sizeof(int)*G->numvertexes);
    for(i=0;i<G->numvertexes;i++)
    {
        etv[i]=0; //每个事件的最早发生时间，都先初始化为0
        if(G->adjlist[i].in==0)
        {
            stack2[top2++]='A'+i; //如果入度为0，入栈
        }
    }
    while(top2!=0)
    {
        gettop=stack2[--top2];
        stack[top++]=gettop;
        count++;
        for(e=G->adjlist[gettop-'A'].first;e;e=e->next)
        {
            j=e->adjvex;
            if(!(--G->adjlist[j].in)) stack2[top2++]='A'+j;
            if((etv[gettop-'A']+e->weight)>etv[j])
            {
                etv[j]=etv[gettop-'A']+e->weight;
            }
        }
    }
    free(stack2);
    if(count<G->numvertexes) return ERROR;
    return OK;
}
void CriticalPath(GraphAdjList *G)
{
    if(!TopologicalSort(G))
    {
        printf("该图存在环!\n");
        free(etv);
        free(stack);
        exit(0);
    }
    edgenode *e;
    int i,j,k;
    char gettop;
    ltv=(int*)malloc(sizeof(int)*G->numvertexes);
    int ete,lte;
    for(i=0;i<G->numvertexes;i++)
    {
        ltv[i]=etv[G->numvertexes-1]; //所有事件最晚发生时间都初始化为拓扑排序最后一个顶点事件的最早发生时间
    }
    while(top!=0)
    {
        gettop=stack[--top];
        for(e=G->adjlist[gettop-'A'].first;e;e=e->next)
        {
            k=e->adjvex;
            if((ltv[k]-e->weight)<ltv[gettop-'A'])
            {
                ltv[gettop-'A']=ltv[k]-e->weight; 
            }
        }
    }
    for(i=0;i<G->numvertexes;i++)
    {
        printf("%c 最早%d 最晚%d\n",G->adjlist[i].vex,etv[i],ltv[i]);
    }
    for(j=0;j<G->numvertexes;j++)
    {
        for(e=G->adjlist[j].first;e;e=e->next)
        {
            k=e->adjvex;
            ete=etv[j];
            lte=ltv[k]-e->weight;
            if(ete != lte)
            {
                printf("<%c->%c 可以延迟%d进行>\n",G->adjlist[j].vex,G->adjlist[k].vex,lte-ete);
            }
            else
            {
                printf("<%c->%c 不可延迟>\n",G->adjlist[j].vex,G->adjlist[k].vex,e->weight);
            }
        }
    }
}