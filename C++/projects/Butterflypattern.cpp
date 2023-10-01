// BUTTERFLY PATTERN
// Enter the size: 5
// *                 * 
// * *             * * 
// * * *         * * * 
// * * * *     * * * * 
// * * * * * * * * * * 
// * * * * * * * * * * 
// * * * *     * * * * 
// * * *         * * * 
// * *             * * 
// *                 * 


#include <iostream>
using namespace std;

int main()
{
     int n,i,j;
     

     cout<<"Enter the size: ";
     cin>>n;

     for(i=1;i<=n;i++)
     {
         for(j=1;j<=i;j++)
         {
             cout<<"* ";
         }
         int c=2*n-2*i; 
         for(j=1;j<=c;j++)
         {
             cout<<"  ";
         }
          for(j=1;j<=i;j++)
         {
             cout<<"* ";
         }

         cout<<endl;

     }


      for(i=n;i>=1;i--)
     {
         for(j=1;j<=i;j++)
         {
             cout<<"* ";
         }
         int c=2*n-2*i; 
         for(j=1;j<=c;j++)
         {
             cout<<"  ";
         }
          for(j=1;j<=i;j++)
         {
             cout<<"* ";
         }

         cout<<endl;

     }


    return 0;
}
