'''
https://leetcode.com/problems/merge-sorted-array/
'''

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        last = m + n - 1 #this will be the last index of nums1
        
        # m - 1 = this will be the last of actual elements in nums1 before 0 elems starts
        # n - 1 = this will be the last of n
        
        # merge in reverse order
        while m > 0 and n > 0: #m and n are ptrs
            if nums1[m - 1] > nums2[n - 1]:
                nums1[last] = nums1[m - 1]
                m -= 1 #decrementing as merging in reverse
            else: 
                nums1[last] = nums2[n -1]
                n -= 1
            last -= 1
        
        # filling num1 with leftover num2 elements
        while n > 0:
            nums1[last] = nums2[n - 1]
            n, last = n -1, last - 1  