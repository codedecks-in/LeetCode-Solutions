# https://leetcode.com/problems/teemo-attacking/
# Difficulty Level: Medium
# Tags: Array
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        
        size = len(timeSeries)
        
        if size == 0:
            return 0
        
        totalTime = duration
        
        for i in range (size - 1):
            
            totalTime += duration
            
            if timeSeries[i+1] < timeSeries[i] + duration:   
                totalTime -= timeSeries[i] + duration - timeSeries[i+1]
                
        return totalTime
            
