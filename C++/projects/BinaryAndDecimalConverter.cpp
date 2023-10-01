#include<bits/stdc++.h>
using namespace std;

void decimalTobinary(int n)
{
    int count = 0, dig;
    int bin[32];

    while(n > 0)
    {
        bin[count] = n % 2;
        n = n / 2;
        count ++;
    }
    
    for(int i = count - 1;i>=0;i--)
    cout << bin[i];
    cout << endl;
}

void binaryTodecimal(int bin[], int count)
{
    int j = 0, decimal = 0;
    for(int i = count - 1;i>=0;i--)
    {
        decimal += pow(2, j) * bin[i];
        j++;
    }

    cout << decimal << endl;
}

int main()
{
    int choice;

    cout << "Press 1 to convert decimal to binary" << endl;
    cout << "Press 2 to convert binary to decimal" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            int n;
            cout << "Enter the decimal number to be converted : ";
            cin >> n;
            decimalTobinary(n);
            break;
        
        case 2:
            string binary;
            cout << "Enter the binary number to be converted : ";
            cin >> binary;

            int bin[32], count = 0;
            for(int i=0;binary[i] != '\0';i++)
            {
                bin[i] = int(binary[i]) - 48;
                count ++;
            }

            binaryTodecimal(bin, count);
            break;
    }

    return 0;
}