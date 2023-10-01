#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string>res;
    int fizz=0,buzz=0;
    for(int i=1;i<=n;i++){
        fizz++;buzz++;
        if(fizz==3 && buzz==5){
            res.push_back("FizzBuzz");
            fizz=0;
            buzz=0;
        }
        else if(fizz==3){
            res.push_back("Fizz");
            fizz=0;
        }
        else if(buzz==5){
            res.push_back("Buzz");
            buzz=0;
        }
        else{
            res.push_back(to_string(i));
        }
    }
    return res;
}
    
int main(){
    int n = 3;
    vector<string> ans = fizzBuzz(n);
    for(auto it:ans){
        cout<< it << " ";
    }
	return 0;
}
