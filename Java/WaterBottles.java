

// https://leetcode.com/problems/water-bottles/


    public int numWaterBottles(int numBottles, int numExchange) {

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
