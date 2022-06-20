#include <stdio.h>
#include <stdlib.h>
void BubbleSort(int *num,int n);
int main()
{
	int n,i;
	int *num;
	printf("请输入数据个数:");
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	BubbleSort(num,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	free(num);
    return 0;
}
void BubbleSort(int *num,int n)
{
    int i,j;
    int temp;
    int flag=1;
    for(i=0;flag&&i<n-1;i++)
    {
    	for(flag=0,j=0;j<n-i;j++)
    	{
    		if(num[j]>num[j+1])
    		{
    			temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
				flag=1;
			}
		}
	}
}
