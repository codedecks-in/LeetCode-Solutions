package com.mani.MathsAssignment;

// https://leetcode.com/problems/water-bottles/
class WaterBottles {
    public static void main(String[] args) {
        System.out.println(numWaterBottles(15,8));
    }

    public static int numWaterBottles(int numBottles, int numExchange) {
//        int rem = numExchange;
//        int sum = numBottles;

//        while(rem >= numExchange){
//
//               rem = numBottles % numExchange ;
//            sum += numBottles;
//
//            numBottles /= numExchange;
//               rem += numBottles;
//
//        }
//        return sum;
        int total = numBottles;
        while(numBottles>=numExchange)
        {
            int exchange=numBottles/numExchange;
            int rem=numBottles%numExchange;
            total+=exchange;
            numBottles=exchange+rem;
        }
        return total;
    }
}