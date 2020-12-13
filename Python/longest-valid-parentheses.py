'''
Speed: 95.97%
Memory: 24.96%
Time complexity: O(n)
Space complexity: O(n)
'''
class Solution(object):
    def longestValidParentheses(self, s):
        ans=0
        stack=[-1]
        for i in range(len(s)):
            if(s[i]=='('):
                stack.append(i)
            else:
                stack.pop()
                if(len(stack)==0):
                    stack.append(i)
                else:
                    ans=max(ans,i-stack[-1])
        return ans