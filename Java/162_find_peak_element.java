class Solution {
    public int findPeakElement(int[] nums) {
        int i=0;
        int j=nums.length-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]<nums[mid+1]){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return i;
    }
}
