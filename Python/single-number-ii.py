class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dict1 = {} # Create hashtable
        # Add counts into the hashtable
        for x in nums:
            if x not in dict1:
                dict1[x] = 1
            else:
                dict1[x] += 1
        # Select the single element
        for ans, y in dict1.items():
            if y == 1:
                return ans

# Or bitwise way
class Solution:
    def singleNumber(self, nums: List[int]) -> int:        
        a, b = 0, 0
        # Just bitwise operation, (notx and a and notb) or (x and nota and b) ... 
        for x in nums:
            a, b = (~x&a&~b)|(x&~a&b), ~a&(x^b)
        return b