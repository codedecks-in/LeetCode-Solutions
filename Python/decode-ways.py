'''
Speed:  93.43%
Memory: 38.43%
Time Complexity: O(n)
'''
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0]=='0':
            return 0
        dp = [0]*(len(s)+1)
        dp[0],dp[1] = 1,1
        for j in range(2,len(s)+1):
            i = j-1
            a = int(s[i])
            b = int(s[i-1:i+1])
            if 0<a<10:
                dp[j]=dp[j-1]
            if s[i-1]!='0' and 0<b<27:
                dp[j]+=dp[j-2]
        return dp[-1]


##Improved
'''
Speed: 93.14%
Memory: 72.58%
'''
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0]=='0':
            return 0
        p,q = 1,1
        for i in range(1,len(s)):
            a = int(s[i])
            y = 0
            if 0<a<10:
                y=q
            if s[i-1]!='0' and 0<int(s[i-1:i+1])<27:
                y+=p
            p,q = q,y
        return q
