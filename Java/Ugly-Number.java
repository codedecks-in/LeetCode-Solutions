class Solution {
    public boolean isUgly(int num) {
        if(num == 0) return false;
        if(num == 1) return true;

        if(num % 2 == 0){
            num = num / 2;
            return isUgly(num);
        }

        if(num % 3 == 0){
            num=num / 3;
            return isUgly(num);
        }

        if(num % 5 == 0){
            num = num / 5;
            return isUgly(num);
        }

        return false;
    }
}

/* adding another solution without recursion */
class Solution {
    public boolean isUgly(int num) {
        if (num <= 0) return false;
        int[] divisors = {2, 3, 5};

        for (int divisor : divisors) {
            while (num % divisor == 0) {
                num /= divisor;
            }
        }

        return num == 1;
    }
}
