#include <stdio.h>
#include<stdlib.h>
int *p2;
int pavan()
{int aq=1;
	printf("%d",*p1);
	//int *p2=malloc(sizeof(int));
	*p2=1;
	while((*p1) > 0)
	{
		if((*p1) %2 ==1)
		{
			(*p2)= (*p2)*(*p);
			//printf("%d %d",*y,*x);
		}
		(*p) = ((*p) * (*p));
		(*p1)=(*p1)/2;
	}
	return *p2;
}
int main()
{
	int x,y,*p;
	scanf("%d %d",&x,&y);
	int *p=malloc(sizeof(int)),*p1=malloc(sizeof(int));
	p=&x;
	p1=&y;
	p2=malloc(sizeof(int));
	printf("%d\n",pavan());
}