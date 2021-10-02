# You are given an integer array nums. You are initially positioned at the array's first index, 
# and each element in the array represents your maximum jump length at that position.
# Return true if you can reach the last index, or false otherwise.

# Input: nums = [2,3,1,1,4]
# Output: true
# Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

# Input: nums = [3,2,1,0,4]
# Output: false
# Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

'''
    Time Complexity: O(n),
    Space Complexity: O(n)
'''

def canJump(nums):
    ptr1 = len(nums) - 1
    ptr2 = ptr1 - 1

    while ptr2 >= 0:
        if nums[ptr2] >= ptr1 - ptr2:
            ptr1 = ptr2
            ptr2 -= 1
        else :
            ptr2 -= 1

    if ptr1 == 0:
        return True
    else:
        return False

print(canJump[3,2,1,0,4])