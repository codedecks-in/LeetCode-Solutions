class Solution {
private:
//solving using brute force: O(n)
public:
    int pivotIndex(vector<int>& nums) {
        int reqSum = 0;
        int total = 0;
        for(auto i : nums){
            total += i;
        }
        for(int i = 0;i<nums.size();i++){
            if(reqSum == (total - reqSum - nums[i])){
                return i;
            }
            reqSum += nums[i];
        }
        return -1;
    }
};
