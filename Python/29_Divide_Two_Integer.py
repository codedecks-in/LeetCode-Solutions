# problem Link: https://leetcode.com/problems/divide-two-integers/
#Time Complexity:   O(n^2)
#Difficulty: Medium
#Runtime: 34ms Beats: 94.50%
#Memory: 13.9MB Beats: 27.40%
class Solution(object):
    def divide(self, dividend, divisor):
       
        positive = (dividend < 0) == (divisor < 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        output = 0
        
        while dividend >= divisor:
            temp = divisor
            multi = 1
            while dividend >= temp:
                dividend -= temp
                output += multi
                multi *= 2
                temp *= 2
        if not positive:
            output = -output
        return min(2147483647, max(-2147483648, output))
