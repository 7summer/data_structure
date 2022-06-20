#include <stdio.h>
void Delete(int l[],int *lenth,int x,int y);
int main()
{
	int l[100];
	int n,i,lenth;
	int x,y;
	printf("请问需要输入多少个数据:");
	scanf("%d",&n);
	lenth=n;
	for(i=0;i<n;i++)
	{
		scanf("%d",&l[i]);
	}
	printf("请输入范围:");
	scanf("%d %d",&x,&y);
	Delete(l,&lenth,x,y);
	for(i=0;i<lenth;i++)
	{
		printf("%d ",l[i]);
	}
	printf("\n");
	return 0;
}
void Delete(int l[],int *lenth,int x,int y)
{
	int i,k;
	i=k=0;
	while(i<*lenth)
	{
		if(l[i]>=x && l[i]<=y)
		{
			k++;
		}
		else
		{
			l[i-k]=l[i];
		}
		i++;
	}
	*lenth-=k;
}

