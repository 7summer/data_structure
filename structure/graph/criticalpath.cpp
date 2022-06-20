#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 30
#define ERROR 0 //����ö������
#define OK 1 //����ö������
typedef int STATUS;
typedef struct edgenode
{
    int adjvex; //�ڽӵ���
    int weight; //Ȩֵ
    struct edgenode *next;
}edgenode;
typedef struct vertexnode
{
    int in; //���
    char vex; //��������
    edgenode *first; //���ӵ�
}vertex,AdjList[MAXVEX];
typedef struct
{
    AdjList adjlist;
    int numvertexes; //������
    int numedges; //����
}GraphAdjList;
int *etv,*ltv; //(����)�¼����翪ʼʱ�� ������ʱ��
char *stack; //����������������
int top=0; //����stack
void CreateGraphAdjList(GraphAdjList *G);
STATUS TopologicalSort(GraphAdjList *G); //��������
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
    printf("�����붥����������:");
    scanf("%d %d%*c",&G->numvertexes,&G->numedges);
    for(i=0;i<G->numvertexes;i++)
    {
        G->adjlist[i].vex='A'+i;
        G->adjlist[i].first=NULL;
        G->adjlist[i].in=0;
    }
    for(i=0;i<G->numedges;i++)
    {
        printf("������ߡ�Ȩֵ:");
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
    int count=0; //�ж�ͼ�Ƿ���ֻ�
    char *stack2; //������������
    stack=(char*)malloc(sizeof(char)*G->numvertexes);
    stack2=(char*)malloc(sizeof(char)*G->numvertexes);
    etv=(int*)malloc(sizeof(int)*G->numvertexes);
    for(i=0;i<G->numvertexes;i++)
    {
        etv[i]=0; //ÿ���¼������緢��ʱ�䣬���ȳ�ʼ��Ϊ0
        if(G->adjlist[i].in==0)
        {
            stack2[top2++]='A'+i; //������Ϊ0����ջ
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
        printf("��ͼ���ڻ�!\n");
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
        ltv[i]=etv[G->numvertexes-1]; //�����¼�������ʱ�䶼��ʼ��Ϊ�����������һ�������¼������緢��ʱ��
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
        printf("%c ����%d ����%d\n",G->adjlist[i].vex,etv[i],ltv[i]);
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
                printf("<%c->%c �����ӳ�%d����>\n",G->adjlist[j].vex,G->adjlist[k].vex,lte-ete);
            }
            else
            {
                printf("<%c->%c �����ӳ�>\n",G->adjlist[j].vex,G->adjlist[k].vex,e->weight);
            }
        }
    }
}