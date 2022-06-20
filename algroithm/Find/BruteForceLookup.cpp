#include <stdio.h>
int search(int num[],int lenth,int key);
int main()
{
    int n,i;
    int num[30]; //num[0]设置为监视哨位
    int key;
    printf("请输入个数:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("请输入要查找的值:");
    scanf("%d",&key);
    i=search(num,n+1,key);
    if(i) printf("%d的位置在%d",key,i);
    else printf("没有找到%d\n",key);
    return 0;
}
int search(int num[],int lenth,int key)
{
    int i;
    num[0]=key;
    for(i=lenth-1;num[i]!=key;i--);
    return i;
}