#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low=0;
    int mid=0;
    int high=nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;mid++;
            //doing this will make us sure that all the numbers before low is 0;
        }
        else if(nums[mid]==1){
            mid++;
            //here we are not increamenting low because if mid gets any 0 in future then arr[low] will be available there to interchange with mid
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
            //here we are not increamenting mid because if let suppose on interchanging we get 1 then it is well and good but in case we get 0 then we need to interchange it with nums[low] otherwise this 0 will remain unsorted
        }
    }
}
    
int main(){
    vector<int>nums = {2,0,1,1,0};
    sortColors(nums);
    for(auto i : nums){
        cout<<i<<" ";
    }
	return 0;
}
