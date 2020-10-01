/*
LeetCode: Pow(x,n)
Link: https://leetcode.com/problems/powx-n/

problem: To caluculate x^n

Constraints:
-100.0 < x < 100.0
-2^31 <= n <= (2^31)-1
-10^4 <= xn <= 10^4

*/ 
class Solution {
    // To caluculate x^n
    public double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        //if power is negative just inverse it    
        if(n<0)
            return 1.0/(x*myPow(x,-(n+1)));
        //for even power    
        if(n%2==0)
            return myPow(x*x,n/2);
        //for odd power
        else
            return x*(myPow(x*x,n/2));
        
    }
}
