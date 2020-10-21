/**
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function (nums) {
  if (!nums.length) return 0;
  let maxEnding = nums[0];
  let minEnding = nums[0];
  let res = nums[0];
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] < 0) {
      let temp = minEnding;
      minEnding = maxEnding;
      maxEnding = temp;
    }

    maxEnding = Math.max(maxEnding * nums[i], nums[i]);
    minEnding = Math.min(minEnding * nums[i], nums[i]);
    res = Math.max(res, maxEnding);
  }
  return res;
};
