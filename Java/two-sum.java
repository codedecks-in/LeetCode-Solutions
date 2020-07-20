/**
* One-pass Hash Table
* we iterate and inserting elements into the table, 
* we also look back to check if current element's complement already exists in the table. 
* If it exists, we have found a solution and return immediately.
*
* Time complexity : O(n)
* Space complexity : O(n)
*/
class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> sumMap = new HashMap<>();
        int [] result = new int[2];
        
        for (int i=0; i<nums.length(); i++){
            
            if(!sumMap.isEmpty() && sumMap.containsKey(nums[i])){
                result[0] = sumMap.get(nums[i]);
                result[1] = i;
                
                return result;
            }
            else{
                sumMap.put(target-nums[i],i);
            }
        }
    }
}
