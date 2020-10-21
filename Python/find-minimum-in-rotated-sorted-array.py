'''
Speed:  37.59%
Memory: 20.90%
Time Complexity: O(logn)
'''
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0]<=nums[-1]:
            return nums[0]
        l,h = 0,len(nums)-1
        while l<=h:
            mid = h - (h-l)//2
            if mid>0 and nums[mid]<nums[mid-1]:
                return nums[mid]
            elif nums[mid]>nums[0]:
                l = mid+1
            else:
                h = mid-1