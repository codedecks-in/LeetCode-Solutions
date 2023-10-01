/* Author: Ajeet Kumar Jaiswal */
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>res;
    unordered_map<int,int>mp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int b=target-nums[i];
        if(mp.find(b)!=mp.end()){
            res.push_back(i);
            res.push_back(mp[b]);
            break;
        }
        mp[nums[i]]=i;
    }
    return res;
}

int main(){
	vector<int> arr = {2,7,11,15};
	int target = 9;
	vector<int>v =twoSum(arr,target);
	for(auto it:v){
		cout<<it<<" ";
	}
	return 0;
}
