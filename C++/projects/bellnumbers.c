#include<stdio.h>
int bellno(int n)
{
	int bell[1005][1005],i,j;
	bell[0][0]=1;
	for(i=1;i<=n;i++)		//this logic of bell numbers is used for calculating no of ways to partitioning a set
	{
		bell[i][0]=bell[i-1][i-1];
		for(j=1;j<=i;j++)
		{
			bell[i][j]=bell[i-1][j-1]+bell[i][j-1];
		}
	}
	return bell[n][0];
}

int main()
{
	int n,ans;
	scanf("%d",&n);
	ans=bellno(n);
	printf("%d\n",ans);
	return 0;
}

