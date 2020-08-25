#Time Complexity:   O(log(n))
#Space Complexity:  O(1)
#Speed: 91.93%
#Memory: 5.97%

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1
        while l <= r:
            m = (l+r)//2
            if m == r and target > nums[m]:
                return m + 1
            if target > nums[m]:
                l = m + 1
            else:
                r = m - 1
        return m