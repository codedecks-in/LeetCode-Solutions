#include <stdio.h>

int main()
{
long long int n,q,i=0,d=1,e,f=0,ans,l,r,x;
scanf("%lld %lld", &n, &q);
long long arr[n+1], diffarr[n+1];
//for(i=0 ; i<n ; i++)
do
{
	scanf("%lld", &arr[i]);
	diffarr[0]=arr[0];
	diffarr[i]=arr[i]-arr[i-1];
	i++;

}
while(i<n);
diffarr[n]=0;
for(i=0 ; i<q ; i++)
{
	scanf("%lld %lld %lld", &l, &r, &x);
	diffarr[l]+=x;
	diffarr[r+1]-=x;
}
arr[0]=diffarr[0];
for(i=1 ; i<n ; i++)
{
	arr[i]=arr[i-1]+diffarr[i];
}
for(i=0 ; i<n ; i++)
{
	e=((arr[i]%1000000007)*(d%1000000007))%1000000007;
	f=(f%1000000007+e%1000000007)%1000000007;
	d=((d%1000000007)*(107%1000000007))%1000000007;
}
if(f<0)
{
	ans=f+1000000007;
}
else
	ans = f;
printf("%lld\n", ans);

return 0;
}
