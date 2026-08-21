class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int>dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++){
            for(auto value : nums){
                if(i - value >= 0 && dp[i] <= INT_MAX)
                  dp[i] += (long long int)dp[i - value];   
            }
        }
        
        return  dp[target];        
    }
};