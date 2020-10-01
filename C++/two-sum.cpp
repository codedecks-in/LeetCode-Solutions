// Brute force solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size();j++){
                if(nums[j] == target-nums[i]){
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }
};