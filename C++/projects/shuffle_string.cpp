#include <bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    // Here we are going to apply cyclic sort
    for(int i=0;i<s.size();i++){
        
        while(indices[i]!=i){
            swap(s[i],s[indices[i]]);
            swap(indices[i],indices[indices[i]]);
        }
    }
    return s;
}
    
int main(){
	string str = "codeleet";
	vector<int>indices = {4,5,6,7,0,2,1,3};
	cout<< restoreString(str,indices);
	return 0;
}
