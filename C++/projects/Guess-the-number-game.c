#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int guess(int number,int value);
int main()
{
    int number,value,count;
    srand(time(0));
    number=rand()%100+1;
    printf("guess the number between 1 to 100 : ");
    scanf("%d",&value);

    count=guess(number,value);
    printf("you won !! in %d turns...",count);
    return 0;
}
int guess(int number,int value)
{
    int count=1;
    while(value!=number)
    {
    if(value>number)
    {
        printf("choose smaller number !!\n");
        scanf("%d",&value);
    }
    else
    {
        printf("choose greater number !!\n");
        scanf("%d",&value);
    }

    count++;
    }
    return count;
}
