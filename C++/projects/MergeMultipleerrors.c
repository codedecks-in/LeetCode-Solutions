// c programe to merge multipole errors

#include <stdio.h>
#include<stdlib.h>
int *p2;
int pavan();

int main()
{
    int x,y,*p;
    scanf("%d %d",&x,&y);
    int *p=malloc(sizeof(int)),*p1=malloc(sizeof(int));
    p=&x;
    p1=&y;
    p2=malloc(sizeof(int));
    printf("%d",pavan());
}