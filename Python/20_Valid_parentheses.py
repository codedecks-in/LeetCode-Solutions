class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(len(s)):
            if s[i] == "(" or s[i] == "[" or s[i] == "{": #check if an open bracket, push to stack
                stack.append(s[i])
            if s[i] == ")" or s[i] == "]" or s[i] == "}": #check if closing bracket, pop from stack and compare
                if len(stack) == 0:
                    return False
                prev = stack.pop()
                if prev == "(" and s[i] != ")":
                    return False
                if prev == "[" and s[i] != "]":
                    return False
                if prev == "{" and s[i] != "}":
                    return False

        if len(stack) == 0:
            return True
        else: 
            return False