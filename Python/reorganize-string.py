'''
speed: 89.11%
memory: 21:02%
N = len(S), A = 1~26(size of diff alpabet)
ex) aab, N=3, A=2
time complexity: O(A * (N + logA))
space complexity: O(N)
'''
class Solution:
    def reorganizeString(self, S: str) -> str:
        n = len(S)
        a= []
        
        for c,x in sorted((S.count(x), x) for x in set(S)):
            if c > (n+1)/2: # not possible
                return ''
            a.extend(c*x)
        
        # empty list
        ans = [None] * n
        
        # placing letters to make possible result
        ans[::2], ans[1::2] = a[n//2:], a[:n//2]
        return "".join(ans)
        
        