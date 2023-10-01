#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n=nums.size();
    int xo=0;
    // So here basically we can use the trick that since all elments are in pair except one of them
    // so why not to take the xor of whole array which would result in that element which exists
    // exactly one time in our array and all other pairs would give us their xor as zeros.
    for(int i=0;i<n;i++){
        xo^=nums[i];
    }
    return xo;
}
    
int main(){
    vector<int> nums = {2,2,1};
    cout<< singleNumber(nums);
	return 0;
}
