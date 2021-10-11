/** 
Given n non - negative integers a1, a2, ..., an, where each represents a point at;
coordinate(i, ai).n vertical lines are drawn such that the two endpoints of the;
line i is at(i, ai) and(i, 0).Find two lines, which, together with the x - axis;
forms a container, such that the container contains the most water.;

Example 1:

Input: height = [1, 8, 6, 2, 5, 4, 8, 3, 7];
Output: 49;
Explanation: The above vertical lines are represented by array
[1, 8, 6, 2, 5, 4, 8, 3, 7].In this case, the max area of water(blue section)
 the container can contain is 49;
*/

// Logic: We use two pointers, one at the start (left) and one at the end (right) of the array. We calculate the maximum
// water that can be contained between these two. If the left barrier is smaller than the right, we advance the left pointer
// otherwise the right. We calculate again the quantity and update the max. Continue this procedure until the pointers meet.

/**
 * @param {number[]} height
 * @return {number}
 */

const maxArea = (height) => {
  let max = 0,
    left = 0,
    right = height.length - 1,
    current = 0;

  while (left < right) {
    current = Math.min(height[left], height[right]) * (right - left);
    max < current ? max = current : max;
    height[left] < height[right] ? left++ : right--;
  }

  return max;
};