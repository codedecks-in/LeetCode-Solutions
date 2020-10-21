'''
Speed: 99.14%
Memory:
Time Complexity: O(n)
'''
class Solution:
    def solve(self, prices):
        # Write your code here
        if len(prices)<2:return 0
        buy = prices[0]
        profit = 0
        for i in range(1,len(prices)):
            if prices[i]<prices[i-1]:
                profit+=prices[i-1]-buy
                buy = prices[i]
        profit+=prices[-1]-buy
        return profit