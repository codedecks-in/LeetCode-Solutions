"""
Question: 
Given a non-empty array of non-negative integers nums,
the degree of this array is defined as the maximum 
frequency of any one of its elements.

Your task is to find the smallest possible length of a
(contiguous) subarray of nums, that has the same degree as nums.

Solution:
Iterate through the list of numbers whike keeping track of the
counter of leftmost and rightmost indices of the numbers
We then find the largest number and return the length  


Time Complexity:  O(n)
Space Complexity: O(n)
"""
import collections

class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: list
        :rtype: int
        """
        counter = collections.Counter(nums)
        left_dict, right_dict = {}, {}
        for i, num in enumerate(nums):
            left_dict.setdefault(num, i)
            right_dict[num] = i
        degree = max(counter.values())
        result = min(right_dict[num]-left_dict[num]+1 \
                   for num in counter.keys() \
                   if counter[num] == degree)
        return result