class Solution {
public:
    int lcs(string& x, string& y, int m, int n, vector<vector<int>>& dp){
        
        //initialization
        //this says if we have string on one side and an empty string on another side 
        //we need to make i edits as per the size of the string 
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i] = i;
        }
        
        /*
        after intitalization:-
        . . a b c d e f
        . 0 1 2 3 4 5 6  
        a 1 - - - - - - 
        z 2 - - - - - -
        c 3 - - - - - -
        e 4 - - - - - -
        d 5 - - - - - -
        
        after thinking of the conditions:-
        filling the table:-
        . . a b c d e f
        . 0 1 2 3 4 5 6  
        a 1 0 1 2 3 4 5 <- here we just need to delete some elements and we get a  
        z 2 1 1 2 3 4 5 <- at b,z we have to see minimum of all 3 (b,a) (a,a) (a,z) and add 1 to them
        c 3 2 2 1 2 3 4 <- at (c,c) value becomes equal so we just take the value of (b,z) ie. i-1 and j-1
        e 4 3 3 2 2 2 3
        d 5 4 4 3 2 3 3
        */
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        
        return dp[m][n];
    }
    int minDistance(string x, string y) {
        int m = x.size();
        int n = y.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        return lcs(x,y,m,n,dp);
    }
};
/*
if word1[i] = word2[j] then f[i][j] = f[i-1][j-1] because we just need to convert i-1 characters of word1 to j-1 characters of word2
if word1[i] != word2[j], here we will have 3 cases :
1.we convert i-1 characters of word1 to j-1 characters of word2 . Then, we replace the character i by character j. In this case, f[i][j] = f[i-1][j-1] + 1
2.we convert i characters of word1 to j-1 characters of word2. Then, we insert the character j to the result. In this case, f[i][j] = f[i][j-1] + 1
3.first we delete the character i from word 1 then we convert i-1 characters of word1 to j characters of word2. In this case, f[i][j] = f[i-1][j] + 1
Therefore, when word[i] != word[j] then f[i][j] = min(f[i][j],f[i-1][j],f[i][j-1]) + 1
*/
