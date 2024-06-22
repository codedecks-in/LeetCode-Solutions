'''3190. Find Minimum Operations to Make All Elements Divisible by Three

You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.Return the minimum number of operations to make all elements of nums divisible by 3.

Example 1:
Input: nums = [1,2,3,4]
Output: 3

Explanation:
All array elements can be made divisible by 3 using 3 operations:
Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.

'''

class Solution:
    def minimumOperations(self, nums: list[int]) -> int:
        count = 0
        for i in nums:
            if i % 3 != 0:
                if (i+1)%3 == 0:
                    count += 1
                if (i-1)%3 == 0:
                    count += 1
        return count