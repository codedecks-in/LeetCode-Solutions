class Solution {
public:
    bool isMatch(string &s, string &p) {
        int is=s.size(), ip=p.size();
        bool dp[is+1][ip+1];

        for(int i=0;i<=is;++i){
            for(int j=0;j<=ip;++j){
                if(i==0 and j==0){
                    dp[i][j] = true;
                }else if(i==0){
                    if(p[j-1]=='*') dp[i][j] = dp[i][j-1];
                    else dp[i][j] = false;
                }else if(j==0){
                    dp[i][j] = false;
                }else{
                    char curS = s[i-1], curP = p[j-1];
                    if(curS==curP){
                        dp[i][j] = dp[i-1][j-1];
                    }else if(curP=='?'){
                        dp[i][j] = dp[i-1][j-1];
                    }else if(curP=='*'){
                        dp[i][j] = (dp[i][j-1] or dp[i-1][j-1] or dp[i-1][j]);
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[is][ip];
    }
};