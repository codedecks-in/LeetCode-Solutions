#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& arr) {
    int n=arr.size();
    // So here we are going to use the concept maximum projectile distance that can be reached
    int curr=0;
    int reachable=0;
    for(int i=0;i<n;i++){
        if(i>reachable){
            return false;
        }
        curr=i+arr[i];
        reachable=max(reachable,curr);
    }
    return true;
}
    
int main(){
    vector<int> arr = {2,3,1,1,4};
    if(canJump(arr)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
	return 0;
}
