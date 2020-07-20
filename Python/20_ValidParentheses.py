# -*- coding: utf-8 -*-
#Difficulty: Easy
#Runtime: 82.23% 
#Memory Usage: 64.83%

"""
Algorithm:
    1. Check a bracket (b) in the string (s), if it contains in parentheses 
    dictionary then we add to stack it's opposite bracket.
    2. If bracket not in parentheses we check does it mach with last bracket in 
    the stack, also we check if stack exists while iterating through the string. 
    If one of this conditions is not True - return False immediately.
    3. After we checked whole string we need to check is stack empty or not and  
    return result.
    4. Result will be true if stack is empty it means all parentheses are valid 
    and closed in the correct order.

Time Complexity =  O(n)
Space Complexity = O(n)
"""

class Solution:
    def isValid(self, s: str) -> bool:
        parentheses = {'(':')', '{':'}', '[':']'}
        stack = []
        for b in s: # take bracket 'b' from string 's'
            if b in parentheses: # if bracket in parentheses
                stack.append(parentheses[b]) # append it's opposite to stack
            elif not stack or stack.pop() != b: # if not stack or bracket not 
                return False                    # equal last bracket in stack
        return not stack # if stack still exists -> False else True