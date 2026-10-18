# LeetCode Problem: Two Sum
# URL: https://leetcode.com/problems/two-sum/
# Language: Python 3

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, v in enumerate(nums):
            need = target - v
            if need in seen:
                return [seen[need], i]
            seen[v] = i

if __name__ == "__main__":
    s = Solution()
    print(s.twoSum([2, 7, 11, 15], 9))
