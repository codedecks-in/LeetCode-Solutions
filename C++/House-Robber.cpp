class Solution {
public:
    int solveMem(int n, vector<int> &nums, vector<int> &dp){
        if(n == 0) return 0;

        if(n == 1) return nums[0];

        if(dp[n] != -1) return dp[n];

        int include = nums[n - 1] +  solveMem(n - 2, nums, dp);
        int exclude = 0 + solveMem(n - 1, nums, dp);
        dp[n] = max(include, exclude);

        return dp[n];
    }

    int solveTab(int n, vector<int> &nums){
        vector<int> dp(n + 1, 0);

        dp[1] = nums[0];

        for(int i = 2; i <= n; i++){
            int include = nums[i - 1] + dp[i - 2];
            int exclude = 0 + dp[i - 1];
            dp[i] = max(include, exclude);
        }
        return dp[n];
    }

    int solveOptimal(int n, vector<int> &nums){

        if(n == 0) return 0;

        if(n == 1) return nums[0];

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 2; i <= n; i++){
            int include = nums[i - 1] + prev2;
            int exclude = 0 + prev1;
            int ans = max(include, exclude);

            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    int rob(vector<int>& nums){
        int n = nums.size();
        //vector<int> dp(n + 1, -1);
        //return solveMem(n, nums, dp);
        //return solveTab(n, nums);

        return solveOptimal(n, nums);
    }
};
