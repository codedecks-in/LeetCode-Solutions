// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/


//Simple Brute force approach:
//For every (i, j, k) calculate the value and finally consider the maximum

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0; // Final Answer
        int length = nums.size();

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                for (int k = j + 1; k < length; k++) {
                    //Calculate the value
                    ans = max(ans, 1ll * (nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return ans;
    }
};