#include<stdio.h>
#include<string.h>
int dp[1005][1005];
int count(int a[],int m,int n)
{
	if(dp[m][n]!=-1)
		return dp[m][n];
	if(n==0)
		return dp[m][n]=1;
	if(n<0)
		return dp[m][n]=0;
	if(m<=0 && n>=1)
		return dp[m][n]=0;
	return dp[m][n]=count(a,m-1,n)+count(a,m,n-a[m-1]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%d",&m);
		int a[m];
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		int n;
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",count(a,m,n));
	}
		return 0;
}
