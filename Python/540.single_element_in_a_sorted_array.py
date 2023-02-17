"""
540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Time Complexity: O(log n)
"""



def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1

        while l <= r:
            mid = (l+r)//2

            if mid==0 or mid==len(nums)-1 or \
                (nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]):
                    return nums[mid]

            if (mid % 2 == 0 and nums[mid] == nums[mid+1]) or \
                (mid % 2 == 1 and nums[mid] == nums[mid-1]):
                l = mid+1
            else:
                r = mid-1