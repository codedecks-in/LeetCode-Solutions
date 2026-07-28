/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution {
  List<int> twoSum(List<int> nums, int target) {
    final Map<int, int> seen = {};

    for (int i = 0; i < nums.length; i++) {
      final int complement = target - nums[i];
      if (seen.containsKey(complement)) {
        return [seen[complement]!, i];
      }

      seen[nums[i]] = i;
    }

    return [];
  }
}
