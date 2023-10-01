#include <stdio.h>
#include <math.h>

int main()
{
	int n,i;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
	{
		long long int k=1;
		long long int r,l,j;
		scanf("%lld %lld", &l, &r);
		if(l==r)
			printf("%lld\n", l);
		else
		{
			if(r!=pow(2,j)-1)
			{
			for(j=0 ; r-pow(2,j)>=0 ; j++)
			{
				k=k<<1;
				k++;
			}
			k=k>>2;
			printf("%lld\n", k);
			}
			else
				printf("%lld\n", r);
		}
	}

	return 0;
}
