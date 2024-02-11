# Difficulty = Easy
# Submission Speed  = 86.40%
'''
The ant returns to the boundary any time the running total of list elements equals zero.
We iterate through the list and increment the count any time the running total is zero.
'''


class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        count = 0
        sum = 0
        for i in range(len(nums)):
            if sum == nums[i] * -1:
                count += 1
            sum += nums[i]
        return count