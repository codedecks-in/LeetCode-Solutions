// Problem: 3Sum
// URL: https://leetcode.com/problems/3sum/description/
// Language: Java
// Author: NayanSaraff
// Steps: Run the Solution class and call threeSum(int[] nums)


class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int fix = 0;

        while(fix<nums.length-2)
        {   
            if(fix>0 && nums[fix] == nums[fix-1])
            {
                fix++;
                continue;
            }
            int l=fix+1,r=nums.length-1;
            while(l<r)
            {
                int sum = nums[fix] + nums[l] + nums[r];

                if(sum >0)
                r--;
                else if(sum < 0)
                l++;
                else
                {
                result.add(Arrays.asList(nums[fix],nums[l],nums[r]));
                l++;
                r--; 

                while(l<r && nums[l] == nums[l-1]) l++;
                while(l<r&& nums[r] == nums[r+1]) r--;
                }
            }
            fix++;
        }
        return result;
    }
}
