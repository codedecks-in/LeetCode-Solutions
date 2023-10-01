#include <stdio.h>
int main()
{
	int n,c=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		int p=0,temp;
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				p=1;
			}
			c++;
		}
		if(p==0)
		{
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d",c);
}