/*
Problem Description :

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Examples:

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find break point
        int break_p=0, min=0, max=nums.size()-1, flag=0;
        
        if(nums[0]>nums[nums.size()-1]){
            while(min<max){
                if(nums[(min+max)/2]>nums[((min+max)/2)+1]){
                    break_p=(min+max)/2;
                    flag=1;
                    break;
                }
                else if(nums[(min+max)/2]>nums[0])
                    min=(min+max)/2;
                else
                    max=(min+max)/2;
            }
        }
        if(flag==1){
        
            //search in first half
            min=0, max=break_p;
            if(target>=nums[min] && target<=nums[max]){
                while(min<max){
                    if(nums[(min+max)/2]==target){
                        return (min+max)/2;
                    }
                    else if(nums[(min+max)/2]>target)
                        max=(min+max)/2;
                    else{
                        min=(min+max+1)/2;
                        cout<<min<<endl;
                    }
                } 
                if(nums[(min+max)/2]==target){
                        return (min+max)/2;
                    }
            }

          //search in second half
            min=break_p+1, max=nums.size()-1;
            if(target>=nums[min] && target<=nums[max]){
                while(min<max){
                    if(nums[(min+max)/2]==target){
                        return (min+max)/2;
                    }
                    else if(nums[(min+max)/2]>target)
                        max=(min+max)/2;
                    else{
                        min=(min+max+1)/2;
                        cout<<min<<endl;
                    }
                } 
                if(nums[(min+max)/2]==target){
                        return (min+max)/2;
                    }
            }
        }
        
        else{
            min=0, max=nums.size()-1;
            if(target>=nums[min] && target<=nums[max]){
                while(min<max){
                    if(nums[(min+max)/2]==target){
                        return (min+max)/2;
                    }
                    else if(nums[(min+max)/2]>target)
                        max=(min+max)/2;
                    else{
                        min=(min+max+1)/2;
                        cout<<min<<endl;
                    }
                } 
                if(nums[(min+max)/2]==target){
                        return (min+max)/2;
                    }
            }
        }
        return -1;
    }
};