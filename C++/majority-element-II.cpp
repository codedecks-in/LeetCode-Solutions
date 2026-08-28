/*   
Problem -
    229. Majority Element II
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
The Optimized Solution -
    Time Complexity: O(N)
    Space Complexity: O(1)
Example -
    Example 1:
        Input: nums = [3,2,3]
        Output: [3]
    Example 2:
        Input: nums = [1]
        Output: [1]
    Example 3:
        Input: nums = [1,2]
        Output: [1,2]
Constraints:
    1 <= nums.length <= 5 * 104
    -109 <= nums[i] <= 109
*/


class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> ans;
            int candidate1 = 0;
            int candidate2 = 1;   // any number different from candidate1
            int countSoFar1 = 0;  // the number of candidate1 so far
            int countSoFar2 = 0;  // the number of candidate2 so far
        
            for (const int num : nums)
              if (num == candidate1) {
                ++countSoFar1;
              } else if (num == candidate2) {
                ++countSoFar2;
              } else if (countSoFar1 == 0) {  // Assign the new candidate.
                candidate1 = num;
                ++countSoFar1;
              } else if (countSoFar2 == 0) {  // Assign the new candidate.
                candidate2 = num;
                ++countSoFar2;
              } else {  // Meet a new number, so pair with the previous counts.
                --countSoFar1;
                --countSoFar2;
              }
        
            const int count1 = ranges::count(nums, candidate1);
            const int count2 = ranges::count(nums, candidate2);
        
            if (count1 > nums.size() / 3)
              ans.push_back(candidate1);
            if (count2 > nums.size() / 3)
              ans.push_back(candidate2);
            return ans;
        }
};