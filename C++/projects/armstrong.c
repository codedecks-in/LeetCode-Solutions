#include<stdio.h>  
int main()    
{    
    int num,rem,sum=0,temp;    
    printf("Enter a number to be checked: ");    
    scanf("%d",&num);    
    temp=num;    
    while(num>0)    
    {    
    rem=num%10;    
    sum=sum+(rem*rem*rem);    
    num=num/10;    
    }    
    if(temp==sum)    
        printf("Armstrong  number ");    
    else    
        printf("Not an Armstrong number");    
    return 0;  
}   
