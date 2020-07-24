/*
*
*
*
*/

class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> left = new HashMap(), right = new HashMap(), count = new HashMap();
 
        //find the leftmost and rightmost index of each characters
        for(int i= 0;i<nums.length; i++)
        {
            int x =nums[i];
            if(left.get(x) == null) 
                left.put(x, i);
            
            right.put(x, i);
            count.put(x, count.getOrDefault(x, 0) + 1);
        }
        
        int ans = nums.length;
        int degree  = Collections.max(count.values());
        
        //find min distance between subarrays with same degree
        for(int x: count.keySet())
        {
            if(count.get(x) == degree)
            {
                ans = Math.min(ans , right.get(x) - left.get(x) + 1);
            }
        }
        return ans;   
    }
}
