class Solution:
def singleNumber(self, nums: List[int]) -> int:
    d = dict()
    for i in range(len(nums)) : 
        if nums[i] not in d : 
            d[nums[i]] = 1
        else:
            d[nums[i]] += 1
    for key, value in d.items() : 
        if value == 1 : 
            return key