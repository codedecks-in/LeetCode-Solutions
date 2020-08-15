/**
* Time Complexity - O(n)
* Space Complexity - O(1)
*
* Using sum of first n natural numbers formula.
*/
class Solution {
    public int missingNumber(int[] nums) {
        int numsLen = nums.length;
        
        // sum of n natural number is
        // Sn = n * (n+1)/2
        int expectedSum = numsLen*(numsLen+1)/2;
        
        // calculate actual sum
        int actualSum = 0;
        for (int i=0; i<numsLen; i++){
            actualSum += nums[i];
        }
        
        // subtract actualSum from expectedSum
        return expectedSum-actualSum;
    }
}
