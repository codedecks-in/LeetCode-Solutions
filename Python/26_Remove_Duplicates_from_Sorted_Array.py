class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        while i<len(nums): #traverse array
            if nums[i] == nums[i-1]: #if the current element is same as previous, then remove
                nums.pop(i)
            else:
                i += 1