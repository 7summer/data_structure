#include <stdio.h>
#include <stdlib.h>
void ShellInsort(int *num,int n,int *d,int t); //d[]���t������������ ����
int main()
{
    int i;
    int temp;
    int n,t=0;
    int *num,*d;
    printf("���������ݸ���:");
    scanf("%d",&n);
    temp=n;
    num=(int*)malloc(sizeof(int)*(n+1));
    d=(int*)malloc(sizeof(int)*n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    while(temp)
    {
        d[t++]=temp/2;
        temp /= 2;
    }
    ShellInsort(num,n,d,t);
    for(i=1;i<=n;i++)
    {
        printf("%d\t",num[i]);
    }
    free(d);
    free(num);
}
void ShellInsort(int *num,int n,int *d,int t)
{
    int i,j,k;
    for(k=0;k<t;k++)
    {
        for(i=d[k]+1;i<=n;i++)
        {
            if(num[i]<num[i-d[k]])
            {
                num[0]=num[i]; //num[0]������λ
                for(j=i-d[k];j>0&&num[0]<num[j];j-=d[k]) //��������˼��
                {
                    num[j+d[k]]=num[j];
                }
                num[j+d[k]]=num[0];
            }
        }
    }
}