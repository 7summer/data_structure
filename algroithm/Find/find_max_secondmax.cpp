#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int i;
	printf("请输入数据个数:");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("输入数据个数异常!\n");
		exit(0);
	}
	int num[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	int max,secondmax;
	max=secondmax=num[0];
	for(i=1;i<n;i++)
	{
		if(max<num[i])
		{
			if(secondmax<max)
			{
				secondmax=max;
			}
			max=num[i];
		}
		else if(max>num[i])
		{
			if(num[i]>secondmax || secondmax>=max)
			{
				secondmax=num[i];
			}
		}
	}
	if(secondmax!=max)
	{
		printf("最大值:%d 次最大值:%d\n",max,secondmax);
	}
	else
	{
		printf("最大值:%d 无次最大值\n",max);
	}
	return 0;
}