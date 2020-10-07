class Solution {
    public int climbStairs(int n) {
        int prev1=1, prev2=2, cur=0;
        if(n<=2) return n;
        for(int i=3;i<=n;++i) {
            cur=prev1+prev2;
            prev1=prev2;
            prev2=cur;
        }
        return cur;
    }
}
