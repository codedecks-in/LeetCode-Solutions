'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
'''
#using Two-Ptrs

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l,r=0,1 #left ptr=buy, right ptr=sell
        maxP=0
        
        while r<len(prices):
            if prices[l]<prices[r]:
                profit=prices[r]-prices[l]
                maxP=max(maxP,profit) #only updates if the current profit is higher
            else:
                l=r
            r+=1
        return maxP