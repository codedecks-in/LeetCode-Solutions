"""
link - https://leetcode.com/problems/valid-parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.


"""


class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)==0:
            return True
        ans=[]
        if s[0] in "]})" :
            return False

        for i in range(0,len(s)):
            try:

                if s[i] in "{([":
                    ans.append(s[i])
                elif s[i]=='}':
                    k=ans.pop()
                    if k!='{':
                        return False
                elif s[i]==']':
                    k=ans.pop()
                    if k!='[':
                        return False
                elif s[i]==')':
                    k=ans.pop()
                    if k!='(':
                        return False
            except:
                return False
        if len(ans)==0:
            return True
        else:
            return False
