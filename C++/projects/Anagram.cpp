#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
    
}
    
int main(){
    string s = "valid";
    string t = "advli";
    if(isAnagram){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
	return 0;
}
