#include<stdio.h>
struct LENGTH
{
    int FEET;
    int INCH;
};
void main()
{
 int I;
 struct LENGTH A,B;
 void add_length(struct LENGTH,struct LENGTH);
 void sub_length(struct LENGTH,struct LENGTH);
 printf("\nENTER LENGTH IN (FEETS AND INCHES FORMAT) FOR FIRST\n");
 printf(" FEETS : ");
 scanf("%d",&A.FEET);
 printf(" INCHES : ");
 scanf("%d",&A.INCH);
 printf("\nENTER LENGTH IN (FEETS AND INCHES FORMAT) FOR SECOND\n");
 printf(" FEETS : ");
 scanf("%d",&B.FEET);
 printf(" INCHES : ");
 scanf("%d",&B.INCH);
 printf("\nSELECT CHOICE");
 printf("\n 1. For ADDITION\n");
 printf("\n 2. For SUBTRACTION\n");
 printf("\nENTER CHOICE HERE :");
 scanf("%d",&I);
 switch(I)
 {
     case 1: add_length(A,B);
   break;
     case 2: sub_length(A,B);
   break;
    
     default: printf("\nYou have Entered Wrong Choice !!!");
 }
}
void add_length(struct LENGTH A,struct LENGTH  B)
{
 struct LENGTH C;
 int INCHS;
 INCHS=(A.FEET*12+A.INCH)+(B.FEET*12+B.INCH);
 C.FEET=INCHS/12;
 C.INCH=INCHS%12;
 printf("\nRESULT OF ADDITION :\n");
 printf("(%dfts %dinchs) + (%dfts %dinchs) = %dfts %dinchs",A.FEET,A.INCH,B.FEET,B.INCH,C.FEET,C.INCH);
}
void sub_length(struct LENGTH A,struct LENGTH  B)
{
 struct LENGTH C;
 int INCHS;
 INCHS=(A.FEET*12+A.INCH)-(B.FEET*12+B.INCH);
 C.FEET=INCHS/12;
 C.INCH=INCHS%12;
 printf("\nRESULT OF SUBSTRACTION :\n");
 printf("(%dfts %dinchs) – (%dfts %dinchs) = %dfts %dinchs",A.FEET,A.INCH,B.FEET,B.INCH,C.FEET,C.INCH);
}


