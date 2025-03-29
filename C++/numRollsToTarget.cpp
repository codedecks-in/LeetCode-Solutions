class Solution {
public:
    int MOD = 1e9+7;
    int rec(int n,int k,int target,vector<vector<int>>& DP)
    {
        if(n == 0 || target <=0)
        {
            if(n!=0) return 0;
            return (target==0)?1:0;
        }
        
        if(DP[n][target] != -1) return DP[n][target];

        int ret = 0;
        for(int i=1;i<=k;i++)
        {
            ret+= rec(n-1,k,target-i,DP);
            ret = ret%MOD;
        }
        DP[n][target] = ret;
        return ret;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> DP(n+1,vector<int>(target+1,-1));
        return rec(n,k,target,DP)%MOD;
    }
};
