'''
Time Complexity: O(m*n)
Space Complexity: O(m*n)
where m and n are lenght of the string and the pattern.
'''

# METHOD 1 -> Recursion plus Memoization

class Solution:
    def helper(self, s, p, idx_s, idx_p,cache):
        if (idx_s,idx_p) in cache:
            return cache[(idx_s,idx_p)]
        
        # if we reach end of both the strings return True
        if idx_p == len(p) and idx_s == len(s):
            return True
        
        # if we reach the end of p but not s then return False
        if idx_p == len(p):
            return False

        # if we reach the end of s but not p then check if the remaining characters in p are * or not
        elif idx_s == len(s):
            res = ( p[idx_p] == '*' and self.helper(s,p,idx_s,idx_p+1,cache) )
        
        # if the current characters of p and s are either equal or char of p is  '?' then continue for other characters
        elif s[idx_s] == p[idx_p] or p[idx_p] == "?":
            res  = self.helper(s,p,idx_s+1,idx_p+1,cache)
           
        # if the current character of p is '*' then either we include it or we leave it
        elif p[idx_p] == '*':
            res = self.helper(s,p,idx_s+1,idx_p,cache) or self.helper(s,p,idx_s,idx_p+1,cache)
        # no char match
        else:
            return False
        cache[(idx_s, idx_p)] = res
        return res
        
    def isMatch(self, s: str, p: str) -> bool:
        return self.helper(s,p,0,0,{})


#METHOD 2 -> Tabulation

class Solution:
        
    def isMatch(self, s: str, p: str) -> bool:
        m,n = len(p),len(s)
        if len(p) - p.count("*") > len(s):
            return False
        
        dp = [[False]*(n+1) for i in range(m+1)]
        for i in range(m+1):
            for j in range(n+1):
                if j==0 and i==0:
                    dp[i][j] = True
                elif i==0:
                    dp[i][j] = False
                elif j==0:
                    dp[i][j] = (p[i-1]=="*" and dp[i-1][j])
                elif p[i-1] == s[j-1] or p[i-1]=='?':
                    dp[i][j] = dp[i-1][j-1]
                elif p[i-1]=='*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
        return dp[m][n]
                
