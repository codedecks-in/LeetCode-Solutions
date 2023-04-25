class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        if (n==1) {
            return (k>=target);
        }
        
        int dp[target+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;     
        
        for (int i=1;i<=k;i++) {
            for (int j=1;j<=k;j++) {
                if (i+j>target)
                    continue;
                
                if (i+j==target && n==2) {
                    ans++;
                }
                
                dp[i+j]++;
            }
        }
        
        if (n==2)
            return ans;
        
        for (int i=3;i<=n-1;i++) {
            
            int dpOld[target+1];
            for (int j=0;j<=target;j++) {
                dpOld[j] = dp[j];
            }
            memset(dp,0,sizeof(dp));
            
            for (int j=1;j<=k;j++) {
                for (int k1 = 1; k1 <= target; k1++) {
                    if (j+k1 > target)
                        continue;
                    dp[j+k1] = (dp[j+k1] + dpOld[k1])%1000000007;
                }
            }
        }
        
        for (int i=1;i<=k;i++) {
            if (target-i>0)
                ans = (ans + dp[target-i])%1000000007;
            
        }        
        return ans;
    }
};