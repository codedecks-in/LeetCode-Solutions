class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)

        # initialise
        dp = [[0]*(n+1) for i in range(m+1)]
        dp[m][n] = 0
        for i in range(m):
            dp[i][n] = m - i
        for i in range(n):
            dp[m][i] = n - i

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                # same char
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i+1][j+1]
                else:
                    dp[i][j] = 1 + dp[i+1][j+1]

                # insertion
                dp[i][j] = min(dp[i][j], 1 + dp[i][j+1])
                # deletion
                dp[i][j] = min(dp[i][j], 1 + dp[i+1][j])
        
        return dp[0][0]

        
