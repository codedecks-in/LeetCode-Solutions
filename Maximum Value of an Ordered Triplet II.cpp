class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixMax(n), suffixMax(n);
        long long ans = 0;
        prefixMax[0] = nums[0];
        suffixMax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], (long long)nums[i]);
            suffixMax[n - i - 1] = max(suffixMax[n - i], (long long)nums[n - i - 1]);
        }
        for (int j = 1; j < n - 1; ++j) {
            if (prefixMax[j] > nums[j]) {
                ans = max(ans, (prefixMax[j] - nums[j]) * suffixMax[j + 1]);
            }
        }

        return ans;
    }
};
