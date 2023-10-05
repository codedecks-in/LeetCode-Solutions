#include <iostream>
using namespace std;
#include <utility>
#include<vector>
int main()
{   
    int n,a,b,e;
    a=0;
    b=0;
    cin>>n;
    while(n--){
        cin>>e;
        if(e<0){
            b=b+e;
        }
        else{
            a=a+e;
        }
    }
    cout<<a-b<<"\n";
}
