#include <stdio.h>
#include <stdlib.h>
void DirectlyInsertSort(int *num,int n); //直接插入排序算法 升序排序
void BiInsertSort(int *num,int n); //折半插入排序算法
int main() 
{
    int n,i;
    int *num;
    printf("请输入数据个数:");
    scanf("%d",&n);
    num=(int*)malloc(sizeof(int)*(n+1));
    for(i=1;i<=n;i++)
    {
        printf("请输入第%d个数据:",i);
        scanf("%d",&num[i]);
    }
    //DirectlyInsertSort(num,n);
    BiInsertSort(num,n);
    for(i=1;i<=n;i++)
    {
        printf("%d\t",num[i]);
    }
    free(num);
    return 0;
}
void DirectlyInsertSort(int *num,int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(num[i]<num[i-1])
        {
            num[0]=num[i]; //num[0]作为监视哨位
            for(j=i-1;num[0]<num[j];j--)
                num[j+1]=num[j];
            num[j+1]=num[0];
        }
    }
}
void BiInsertSort(int *num,int n)
{
    int i,j,low,high,mid;
    for(i=2;i<=n;i++)
    {
        num[0]=num[i];
        low=1;
        high=i-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(num[0]<num[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=high+1;j--)
            num[j+1]=num[j];
        num[high+1]=num[0]; //num[low]=num[0]
    }
}