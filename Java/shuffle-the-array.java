class Solution {
    public int[] shuffle(int[] nums, int n) {
        int [] result = new int[2 * n];
        
        // Looping over the array
        for(int i = 0; i < 2 * n; i ++){
            // If the array index is even
            if(i % 2 == 0)
                result[i] = nums[i / 2];

            // If it's not even, its odd
            else
                result[i] = nums[n + i / 2];
        }

        return result;
    }
}