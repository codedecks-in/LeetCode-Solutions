 /*   

Problem -
    152. Maximum Product Subarray
    Given an integer array nums, find a subarray that has the largest product, and return the product.

The Optimized Solution -
    Time Complexity: O(N)
    Space Complexity: O(1)

Example -
    Input: nums = [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {

    int max_end = nums[0];
    int min_end = nums[0];
    int max_so_far = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int temp = max({ nums[i], nums[i] * max_end, nums[i] * min_end });
        min_end = min({ nums[i], nums[i] * max_end, nums[i] * min_end });
        max_end = temp;
        max_so_far = max(max_so_far, max_end);
    }

    return max_so_far;
    }
};