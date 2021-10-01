package com.mani.MathsAssignment;

// https://leetcode.com/problems/sign-of-the-product-of-an-array/
class SignOf {
    public static void main(String[] args) {
        int[] nums = {-1,1,-1,1,-1};
        System.out.println(arraySign(nums));
    }
    public  static int arraySign(int[] nums) {
        int count = 0;
        for(int i : nums){
            if(i == 0){
                return 0;
            }else if(i < 0){
                count++;
            }
        }
        if(count % 2 == 0){
            return 1;
        }
        return -1;
    }
}