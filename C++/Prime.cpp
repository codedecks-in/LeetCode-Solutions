#include <iostream>
#include<math.h>
#include<conio.h>
using namespace std;

int prime(int);

int main()
{
   bool isPrime;
   int p;
   cout<<"Enter the limit"<<endl;
   cin>>p;
   for(int n = 2; n < p; n++) {
   	
      isPrime = prime(n);

      if(isPrime == true)
         cout<<n<<" "<<endl;
   }
   return 0;
}
int prime(int n) {
   bool isPrime = true;

   for(int i = 2; i <= sqrt(n); i++) {
   	
      if (n%i == 0) {
         isPrime = false;
         break;
      }
   }  
   return isPrime;
}
