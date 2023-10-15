/**
 * 34. Find First and Last Position of Element in Sorted Array
 * Medium
 * 
 * Given an array of integers nums sorted in non-decreasing order,
 * find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * 
 * Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
 * 
 * Logic : loop through the given array and when target number is found
 * set the index as starting position only if the index is first position
 * or previous number is not equal to target. For last position keep on 
 * updating the last position when ever value is equal to target
 * 
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

var searchRange = function (nums, target) {
  let first = -1;
  let last = -1;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] == target && (i == 0 || nums[i - 1] != target)) first = i;
    if (nums[i] == target) last = i;
  }
  return [first, last];
};
