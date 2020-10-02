// This is a Dynamic Programming Problem
// The problem directly translates to the fibonacci problem
// F(n) = F(n-1) + F(n-2) where F(n) is the number of ways to reach nth stair

class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
