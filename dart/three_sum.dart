/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
  List<List<int>> threeSum(List<int> nums) {
    nums.sort();
    final List<List<int>> ans = [];

    for (int i = 0; i < nums.length - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = nums.length - 1;

      while (left < right) {
        final int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0) {
          ans.add([nums[i], nums[left], nums[right]]);
          left++;
          right--;

          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }

          while (left < right && nums[right] == nums[right + 1]) {
            right--;
          }
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }

    return ans;
  }
}
