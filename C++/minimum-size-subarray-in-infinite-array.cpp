// https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/
/*
    Approach:
    The problem is similar to 'Find minimum length circular subarray such that it's sum  == 
    target.', but with a slight twist.

    Here we are given to consider array of infinite length, (concatenate the array multiple
    times). Let's say sum of all the numbers in a single array = S.

    So if we think about it:
    if target <= S, we have to consider only one instance of the array

    but if target > S:
    Here, we have to consider multiple instances. We can do it in the following way:
    (sum of some last elements) + k*(sum of the array) + (sum of some front elements)

    The (sum of some front elements) + (sum of some last elements) is = to target%S and 
    k = (target/S) * n

    minimum length circular subarray such that it's sum  == target%S can be calculated by
    using the sliding window technique.
*/

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();

        // Calculate the sum of all elements
        long long sum = accumulate(nums.begin(),nums.end(),0ll);

        // If target > sum, then we have to consider multiple copies of the array, hence we
        // initialize the ans to number of elements we have to definitely consider and rest we
        // calculate.
        int ans = (target/sum) * n;
        target%=sum;

        // Finding minimum length circular subarray such that sum of it == target.
        // Using sliding window technique for the calculation. 
        int mn = INT_MAX, st = 0, ed = 0;
        long long tempSum = 0;
        for(; ed<2*n; ed++){
            tempSum += nums[ed%n];
            while(tempSum>target){
                tempSum -= nums[st%n];
                st++;
            }
            if(tempSum == target){
                mn = min(mn, ed-st+1);
            }
        }

        if (mn == INT_MAX) return -1;

        ans+=mn;
        return ans;
    }
};