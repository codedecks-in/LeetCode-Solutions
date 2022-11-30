/**
* Time Complexity - O(nlogn+n)
* Space Complexity - O(1)
**/

class Solution {
    
    //  Using sum of first n natural numbers formula.
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
    
    // Using XOR approach
    public int missingNumber(int[] nums) {
        int numsLen = nums.length;
        
        int xor = numsLen;
        
        for(int i=0; i<numsLen; i++){
            xor ^= nums[i] ^ i;
        }
        
        return xor;
    }
    
    // using quick sort 
 public int missingNumber(int[] nums) {
Arrays.sort(nums);//O(nlog(n))
int a=0;
for(int i=0;i<nums.length;i++){//O(n)
if(nums[a]!=i){
return i;
}
a++;
}
return nums.length;
    }

}
