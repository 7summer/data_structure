#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int i;
	printf("���������ݸ���:");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("�������ݸ����쳣!\n");
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
		printf("���ֵ:%d �����ֵ:%d\n",max,secondmax);
	}
	else
	{
		printf("���ֵ:%d �޴����ֵ\n",max);
	}
	return 0;
}