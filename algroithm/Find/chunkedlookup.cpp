#include <stdio.h>
typedef struct
{
    int key; //保存每一块中的最大值
    int link; //每一块开始的序号
}IdxType;
typedef IdxType Idx[10];
typedef struct
{
    int num[30];
    int lenth; //数据元素的个数
    int b; //索引表元素个数
}stable;
void CreatIdx(stable *ST,Idx I);
int Idxsearch(stable *ST,Idx I,int b,int key); //S是存储数据的数组 I是索引表 b为索引表中元素个数 key为要查找的数据
int main()
{
    stable ST;
    Idx I;
    int key;
    int flag;
    CreatIdx(&ST,I);
    do
    {
        printf("请输入需要查找的数据:");
        scanf("%d",&key);
        flag=0;
        if(key!=-1) flag=Idxsearch(&ST,I,ST.b,key);
        if(flag) printf("%d在%d的位置\n",key,flag);
        else if(key!=-1) printf("没有找到%d\n",key);
    } while (key!=-1);
    
    return 0;
}
void CreatIdx(stable *ST,Idx I)
{
    int n,b;
    int i,j;
    int temp;
    int s;
    printf("请输入元素个数:");
    scanf("%d",&n);
    ST->lenth=n;
    printf("请输入索引表元素个数:");
    scanf("%d",&b);
    s=n/b;
    ST->b=b;
    for(i=0;i<n;i++)
    {
        printf("请输入数据:");
        scanf("%d",&ST->num[i]);
    }
    for(i=0;i<b;i++)
    {
        I[i].link=b*i;
        temp=ST->num[b*i];
        for(j=b*i+1;j<b*i+3;j++)
        {
            if(temp<ST->num[j])
            {
                temp=ST->num[j];
            }
        }
        I[i].key=temp;
    }
}
int Idxsearch(stable *ST,Idx I,int b,int key)
{
    int low=0,high=b-1,mid;
    int i,j;
    int s=ST->lenth/b; //每一块的数据个数
    while(low<=high)
    {
        mid=(low+high)/2;
        if(I[mid].key>=key) high=mid-1;
        else low=mid+1; 
    }
    if(low>b) return 0; //查找不到
    if(I[low].link+s>ST->lenth) j=ST->lenth;
    else j=I[low].link+s-1; //j为所找到的块的最后一个元素的下标
    for(i=I[low].link;i<=j&&ST->num[i]!=key;i++);
    if(i<=j) return i;
    return 0;
}