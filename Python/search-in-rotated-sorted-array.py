"""
Time Complexity: O(logn)
Space Complexity: O(1)

Point to observe: Each time either the left half will be sorted or the right half.
Hence Binary Search is a good option.
"""

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        low  = 0
        high = n-1
        while low<=high:
            mid = (low+high)//2
            if nums[mid]==target:
                return mid
            
            # if left half is sorted 
            if nums[low]<=nums[mid]:
                if nums[low]<=target<nums[mid]:
                    high = mid-1
                else:
                    low = mid+1
                    
            # if right half is sorted
            else:
                if nums[mid]<target<=nums[high]:
                    low = mid+1
                else:
                    high = mid-1
        return -1
                    
            
        
