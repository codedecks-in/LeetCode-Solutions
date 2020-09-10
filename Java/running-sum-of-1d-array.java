/**
* Running Sum of 1d Array
* 
* Time Complexity - O(n)
* Space Complexity - O(n)
*
* Runtime: 0 ms, faster than 100.00% of Java online submissions
*/
class Solution {
    public int[] runningSum(int[] nums) {
        
        int len = nums.length;
        int[] runningSumAr = new int[len];
        
        int sumSoFar = 0;
        
        for(int i=0; i<len; i++){
            sumSoFar += nums[i];
            
            runningSumAr[i] = sumSoFar;
        }
        
        return runningSumAr;
    }
}
