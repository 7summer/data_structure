#include <stdio.h>
#define MAXE 30 //������
struct edges
{
    int bv,tv,w; //�洢һ���ߵ���Ϣ bv�洢��ʼ���� tv�洢��ֹ���� w�洢Ȩֵ
};
typedef struct edges edgeset[MAXE];
int seeks(int set[],int v); //set�жϱ����֮���Ƿ���ֻ� v�������λ��
void kruskal(edgeset ge,int n,int e); //ge��ʾ��ͼ�ǰ�Ȩֵ��С�������е� n��������� e�������
void selectsort(edgeset ge,int e);
int main()
{
    edgeset ge;
    int n,e,w;
    int i,j,k;
    printf("�����붥����������:");
    scanf("%d %d",&n,&e);
    for(i=1;i<=e;i++)
    {
        printf("��������ʼ�������ֹ�����Ȩֵ:");
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
    for(i=1;i<=n;i++) set[i]=0; //һ��ʼ�����߶�û�й�ϵ
    i=1; //i��ʾge�е��±ꡣ��ֵΪ1
    j=1; //��ȡ���������еı���
    while(j<n && i<=e)
    {
        v1=seeks(set,ge[i].bv); //ȷ������bv���ڵı߼�
        v2=seeks(set,ge[i].tv); //ȷ������tv���ڵı߼�
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
