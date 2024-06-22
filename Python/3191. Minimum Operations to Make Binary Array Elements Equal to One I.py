'''3191. Minimum Operations to Make Binary Array Elements Equal to One I

You are given a binary array nums.You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.Flipping an element means changing its value from 0 to 1, and from 1 to 0.Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

Example 1:
Input: nums = [0,1,1,1,0,0]
Output: 3
Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
'''

class Solution:
    def minOperations(self, nums: list[int]) -> int:
        i = 0
        count = 0
        while (i+2) < len(nums):
            if nums[i] == 0:
                nums[i] = 1
                if nums[i+1] == 1:
                    nums[i+1] = 0
                else:
                    nums[i+1] = 1
                    
                if nums[i+2] == 1:
                    nums[i+2] = 0
                    
                else:
                    nums[i+2] = 1
                count += 1
            i += 1
            
        for j in nums:
            if j != 1:
                return -1
        return count