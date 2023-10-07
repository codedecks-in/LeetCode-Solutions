// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
// Optimized Version of maximum-value-of-an-ordered-triplet-i problem

/*
    Approach:
    Since we want to maximize (nums[i] - nums[j]) * nums[k] and i < j < k, we see that for
    nums[i] we can only take values before jth index and for nums[k] we can only take values 
    after jth index. 

    Since we want to maximize the expression, nums[i] and nums[k] should be maximum with
    respect to the jth position. Hence, we can use prefix-max concept. We can create two arrays
    max_left and max_right.
    
    max_left[i] ---> max of all the numbers before ith index
    max_right[i] ---> max of all the numbers after ith index

    Finally we iterate from j = 0 to j = nums.size() and calculate the expression:
    (max_left[i] - nums[j]) * max_right[k]

    Finally we record the max value of the expression, and return it.
*/


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        // Initializing vectors with value = 0 (Min value nums[i] can take)
        vector<int> max_left(n,0);
        vector<int> max_right(n,0);

        // Calculating max from left
        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], nums[i - 1]);
        }

        // Calculating max from right
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], nums[i + 1]);
        }

        // Calculating the expression for every i and recording the maximum
        long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            long temp = (max_left[i] - nums[i]) * ((long) max_right[i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};