#include <stdio.h>
#include <stdlib.h>
void AdjustTree(int *num,int n,int k); //n为最大下标值 k为调整点下标
void HeapSort(int *num,int n); //n为num的数据个数
int main()
{
    int n,i;
    int *num;
    printf("请输入数据个数:");
    scanf("%d",&n);
    num=(int*)malloc(sizeof(int)*(n+1));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    HeapSort(num,n);
    for(i=1;i<=n;i++)
    {
        printf("%d\t",num[i]);
    }
    free(num);
    return 0;
}
void AdjustTree(int *num,int n,int k)
{
    int i,j;
    i=k;
    j=2*i;
    num[0]=num[i];
    while(j<=n)
    {
        if(j<n && num[j+1]>num[j])
            j=j+1;
        if(num[0]>num[j])
            break;
        num[i]=num[j];
        i=j;
        j=2*i;
    }
    num[i]=num[0];
}
void HeapSort(int *num,int n)
{
    int i;
    int t;
    for(i=n/2;i>=1;i--)
        AdjustTree(num,n,i);
    for(i=n;i>=2;i--)
    {
        t=num[i];
        num[i]=num[1];
        num[1]=t;
        AdjustTree(num,i-1,1);
    }
}
