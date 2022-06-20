#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 30
#define MAXCOST 1000
void prin(int c[MAXVEX][MAXVEX],int n); //c��ű� n���������
int main()
{
    int c[MAXVEX][MAXVEX];
    int n;
    int i,j;
    int lowcost;
    printf("������ͼ�Ķ������:");
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
        printf("������ͼ�ı�:");
        scanf("%d %d",&i,&j);
        printf("������ͼ��Ȩֵ:");
        scanf("%d",&lowcost);
        c[i][j]=lowcost;
        c[j][i]=lowcost;
    } while (i!=0 && j!=0);
    prin(c,n);
    return 0;
}
void prin(int c[MAXVEX][MAXVEX],int n)
{
    int i,j,k,min; //min���������С��Ȩֵ
    int lowcost[MAXVEX],closest[MAXVEX]; //lowcost������űߵ�Ȩֵ closest�ж϶����Ƿ���������ӵĶ���
    for(i=2;i<=n;i++)
    {
        lowcost[i]=c[1][i];
        closest[i]=1; 
    }
    closest[1]=0; //����һ��������뵽��С������
    for(i=2;i<=n;i++)
    {
        min=MAXCOST;
        for(j=1;j<=n;j++) //ѡ����С��Ȩֵ
        {
            if(closest[j]!=0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        printf("(%d,%d)\n",closest[k],k); //closest[k]������� k�����
        closest[k]=0; //����k��������뵽��С������
        for(j=2;j<=n;j++) 
        {
            if(closest[j]!=0 && c[k][j]<lowcost[j]) //���¶�lowcost closest��ֵ
            {
                lowcost[j]=c[k][j];
                closest[j]=k;
            }
        }
    }
}
