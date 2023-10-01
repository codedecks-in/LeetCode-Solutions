#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};
void display(struct node* head)
{
    while(head->next!=NULL)
    {
        printf("%dX^%d + ",head->coeff,head->power);
        head=head->next;
    }
    printf("%dX^%d",head->coeff,head->power);
}
void create(struct node ** head)
{
    int n;
    struct node *temp;
    struct node *temp1;
    struct node *current;struct node *prev;
    printf("Enter the elements to be inserted");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value of coefficient and exponent : \n");
        scanf("%d%d", &(newNode->coeff), &(newNode->power));
        newNode->next=NULL;
        temp=*head;
        
        if(*head==NULL || ((*head)->power)>newNode->power)
        {
            newNode->next=*head;
            *head=newNode;
        }
        else
        {
            temp=*head;
            while( temp->power<newNode->power && temp!=NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
            newNode->next=temp;
            temp1->next=newNode;
            
        }
    }
    display(*head);
}
void main()
{
    struct node *head=NULL;
    create(&head);
}