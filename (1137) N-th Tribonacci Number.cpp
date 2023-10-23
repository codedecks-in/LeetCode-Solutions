//  N-th Tribonacci Number
// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

// EXAMPLE 1
// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4


// SOLUTION
class Solution {
public:
    int tribonacci(int n) 
    {
        int i,j,k,ans=0;
        vector<int>result;
        result.push_back(0);
        result.push_back(1);
        result.push_back(1);
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }
        else if(n==2)
        {
            return 1;
            
        }
        else
        {
            for(i=3;i<=n;i++)
            {
                ans=result[i-1]+result[i-2]+result[i-3];
                result.push_back(ans);
            }
        }
        return result[n];
    }
};


// CONSTRAINTS
// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1
  
