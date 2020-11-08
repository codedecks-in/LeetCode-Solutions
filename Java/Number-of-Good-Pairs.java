class Solution {
    public int numIdenticalPairs(int[] nums) {
        int numGoodPairs = 0;
        
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i == j) continue; // cannot check against itself
                if (nums[i] == nums[j] && i < j) numGoodPairs++;
            }
        }
        
        return numGoodPairs;
    }
}
