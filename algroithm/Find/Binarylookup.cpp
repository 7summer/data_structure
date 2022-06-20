#include <stdio.h>
int binsearch(int num[],int lenth,int key);
int main()
{
    int num[30];
    int n,i;
    int key;
    printf("请输入个数:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("请输入你需要找的值:");
    scanf("%d",&key);
    i=binsearch(num,n,key);
    if(i!=-1) printf("%d的位置在%d\n",key,i);
    else printf("%d没有被找到!\n",key);
    return 0;
}
int binsearch(int num[],int lenth,int key)
{
    int low,high,mid;
    low=0;
    high=lenth-1;
    while(low<=high)
    {
        mid=(low+high)/2; //1 2 4 5 7
        if(num[mid]==key) return mid;
        if(num[mid]>key) high=mid-1;
        else low=mid+1;
    }
    return -1;
}