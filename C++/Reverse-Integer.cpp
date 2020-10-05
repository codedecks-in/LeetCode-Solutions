# include<iostream.h>
void main()
{
    int x,digit;
    cout<<"Enter your integer:-";
    cin>>x;                      //Input
    int rev = 0;
    while (x>0) 
    {
        digit = x % 10;              //extrracting a digit
        rev = rev * 10 + digit;      //making the reverse
        x/=10;                       // removal of extracted digits
    }
    cout<<"The reverse of the number is "<<rev;  //Output or display of the reversed number
}

