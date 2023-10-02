class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>&dp){
      //Base Cases
       if(ind < 0) return 0;
       if(ind == 0) return nums[ind];

       if(dp[ind] != -1) return dp[ind];

      //Pick and NotPick
       int take = 0,nottake =0;
      
       take = nums[ind] + solve(ind - 2, nums,dp);
       nottake = 0 + solve(ind - 1, nums,dp);

      //Memoize and return maximum
       return dp[ind] = max(take,nottake); 
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
      
        vector<int> nums1, nums2;
        for(int i = 0;i < n;i++){
            if(i != 0)
            nums1.push_back(nums[i]);
            if(i != n - 1)
            nums2.push_back(nums[i]);
        }
      
        vector<int>dp(101, -1);
        int a = solve(n - 2, nums1,dp);
      
        fill(dp.begin(),dp.end(),-1);
        int b =  solve(n - 2, nums2,dp);
      
        return max(a,b);
    }
};
