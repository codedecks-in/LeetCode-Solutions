// 3Sum

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> li = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0 ; i< nums.length ; i++){
            if(i==0 || nums[i-1] != nums[i]){
                int low = i+1;
                int high = nums.length-1;
                int sum = -nums[i];
                if(sum>=0){
                    while(low<high){
                    if(nums[low]+nums[high]==sum){
                        li.add(Arrays.asList(nums[i] , nums[low] , nums[high]));
                        while(low<high && nums[low]==nums[low+1])low++;
                        while(low<high && nums[high]==nums[high-1])high--;
                        low++;
                        high--;
                    }
                    else if(nums[low]+nums[high] > sum)
                        high--;
                    else
                        low++;
                }
                }
            }
        }
        return li;
    }
}
