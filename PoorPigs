class Solution {
public:
    int poorPigs(int N, int I, int T) {
        vector<long long> f(11, 1);
        for(int i = 1; i <= 10; i++) f[i] = f[i - 1] * i;
        T = T / I;
        if(N == 1) return 0LL;
        vector<vector<int>> dp(11, vector<int> (T + 1));
        for(int i = 0; i <= 10; i++) dp[i][0] = 1;
        for(int i = 0; i <= T; i++) dp[0][i] = 1;
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= T; j++){
                for(int k = 0; k <= i; k++) dp[i][j] += f[i] / (f[i - k] * f[k]) * dp[i - k][j - 1];
            }
            if(dp[i][T] >= N) return i;
        }
        return 11LL;
    }
};
