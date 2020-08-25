'''
Speed:              5.11%
Memory:             9.88%
Time Complexity:    O(N^2)
'''
class Solution:
    def divisorGame(self, N: int) -> bool:
        dp = [False]*(N+1)
        for i in range(N+1):
            for j in range(1,i):
                if i%j==0 and dp[i-j]==False:
                    dp[i] = True
        return dp[N]