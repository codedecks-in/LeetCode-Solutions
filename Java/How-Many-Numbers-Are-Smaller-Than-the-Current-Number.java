//How Many Numbers Are Smaller Than the Current Number

//Simple and easy to understandable approach which is beginner friendly

//Runtime: 29 ms
//Memory Usage: 45 MB


class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] output = new int[nums.length];
        
        
        
        for(int i = 0 ; i < nums.length ; i++){
            int count =0;
            for (int j = 0 ; j < nums.length ; j++){
                if (j!=i && nums[j]<nums[i]){
                    count++;
                    
                }
                
                 
            }
           output[i]= count;
            
        }
        return output;
    }
}

/* 
TEST CASES

Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Input: nums = [7,7,7,7]
Output: [0,0,0,0] */
