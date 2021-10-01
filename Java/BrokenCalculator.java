package com.mani.MathsAssignment;
// https://leetcode.com/problems/broken-calculator/
class BrokenCalculator {
    public static void main(String[] args) {
        System.out.println(brokenCalc(2,3));
    }

    public static int brokenCalc(int startValue, int target) {

//        if(startValue == target){
//            return 0;
//        }
//
//        return 1 + Math.min( brokenCalc(startValue - 1,target),brokenCalc(startValue * 2,target));

        if(startValue >= target){
            return  startValue - target;
        }

        if(target % 2 == 0){
            return  1+brokenCalc(startValue,target/2);
        }

        return  1+brokenCalc(startValue,target+1);

    }
}