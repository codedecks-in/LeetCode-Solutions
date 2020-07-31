'''
Time Complexity: O(n^3)
Space complexity: O(n)
'''

# Method 1 : memoization

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dict=set(wordDict)
        dp = {}
        def helper(s,dict,dp):
            if s in dp:
                return dp[s]
            l=len(s)
            if l==0:
                return True
            for i in range(l):
                if s[:i+1] in dict and helper(s[i+1:],dict,dp):
                    dp[s[:i+1]] = True
                    return True
            dp[s] = False
            return False
        return helper(s,dict,dp)
    

# Method 2 : Tabulation
'''
create an array of n+1 elements
dp[0] represent empty string and it will be True as we can find it.
Here dp[i] represent if s[:i+1] can be found in wordDict or not.
if dp[i] is found then check for remaining characters in s that is s[i:]
our result will be on last index of the dp array.
'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        word = set(wordDict)
        dp = [False]*(n+1)
        dp[0] = True
        for i in range(len(s)+1):
            if dp[i] == True:
                for j in range(i+1,len(s)+1):
                    if s[i:j] in word:
                        dp[j] = True
        return dp[n]
            
