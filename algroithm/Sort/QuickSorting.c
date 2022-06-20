#include <stdio.h>
#include <stdlib.h>
void HoareSort(int *num,int low,int high);
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
    HoareSort(num,1,n);
    for(i=1;i<=n;i++)
    {
        printf("%d\t",num[i]);
    }
    free(num);
}
void HoareSort(int *num,int low,int high)
{
    int i,j;
    if(low<high)
    {
        i=low;
        j=high;
        num[0]=num[i]; //监视哨位
        while(i<j)
        {
            while(i<j && num[j]>=num[0]) j--;
            num[i]=num[j];
            while(i<j && num[i]<num[0]) i++;
            num[j]=num[i];
        }
        num[i]=num[0];
        HoareSort(num,low,i-1);
        HoareSort(num,i+1,high);
    }
}