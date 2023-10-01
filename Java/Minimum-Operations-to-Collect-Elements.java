/*
2869. Minimum Operations to Collect Elements

problem definition: You are given an array nums of positive integers and an integer k.
In one operation, you can remove the last element of the array and add it to your collection.
Return the minimum number of operations needed to collect elements 1, 2, ..., k.

Input: nums = [3,1,5,4,2], k = 2
Output: 4
Explanation: After 4 operations, we collect elements 2, 4, 5, and 1, in this order. Our collection contains elements 1 and 2. Hence, the answer is 4.



*/


class Solution {
    public int minOperations(List<Integer> nums, int k) {
        //use Set to ignore the addition of a duplicate element
        Set<Integer> target = new HashSet<>();
        int ans=0;
        for (int i=nums.size()-1; i>= 0; i--) {
            ans++;
            if(nums.get(i)<=k){
                target.add(nums.get(i));
            }
            if(target.size()==k) break;
        }

        return ans;
    }
}
