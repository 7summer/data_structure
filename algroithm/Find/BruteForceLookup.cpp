#include <stdio.h>
int search(int num[],int lenth,int key);
int main()
{
    int n,i;
    int num[30]; //num[0]����Ϊ������λ
    int key;
    printf("���������:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("������Ҫ���ҵ�ֵ:");
    scanf("%d",&key);
    i=search(num,n+1,key);
    if(i) printf("%d��λ����%d",key,i);
    else printf("û���ҵ�%d\n",key);
    return 0;
}
int search(int num[],int lenth,int key)
{
    int i;
    num[0]=key;
    for(i=lenth-1;num[i]!=key;i--);
    return i;
}