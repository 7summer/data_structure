#include <stdio.h>
typedef struct
{
    int key; //����ÿһ���е����ֵ
    int link; //ÿһ�鿪ʼ�����
}IdxType;
typedef IdxType Idx[10];
typedef struct
{
    int num[30];
    int lenth; //����Ԫ�صĸ���
    int b; //������Ԫ�ظ���
}stable;
void CreatIdx(stable *ST,Idx I);
int Idxsearch(stable *ST,Idx I,int b,int key); //S�Ǵ洢���ݵ����� I�������� bΪ��������Ԫ�ظ��� keyΪҪ���ҵ�����
int main()
{
    stable ST;
    Idx I;
    int key;
    int flag;
    CreatIdx(&ST,I);
    do
    {
        printf("��������Ҫ���ҵ�����:");
        scanf("%d",&key);
        flag=0;
        if(key!=-1) flag=Idxsearch(&ST,I,ST.b,key);
        if(flag) printf("%d��%d��λ��\n",key,flag);
        else if(key!=-1) printf("û���ҵ�%d\n",key);
    } while (key!=-1);
    
    return 0;
}
void CreatIdx(stable *ST,Idx I)
{
    int n,b;
    int i,j;
    int temp;
    int s;
    printf("������Ԫ�ظ���:");
    scanf("%d",&n);
    ST->lenth=n;
    printf("������������Ԫ�ظ���:");
    scanf("%d",&b);
    s=n/b;
    ST->b=b;
    for(i=0;i<n;i++)
    {
        printf("����������:");
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
    int s=ST->lenth/b; //ÿһ������ݸ���
    while(low<=high)
    {
        mid=(low+high)/2;
        if(I[mid].key>=key) high=mid-1;
        else low=mid+1; 
    }
    if(low>b) return 0; //���Ҳ���
    if(I[low].link+s>ST->lenth) j=ST->lenth;
    else j=I[low].link+s-1; //jΪ���ҵ��Ŀ�����һ��Ԫ�ص��±�
    for(i=I[low].link;i<=j&&ST->num[i]!=key;i++);
    if(i<=j) return i;
    return 0;
}