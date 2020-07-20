#Difficulty = Easy
#Submission Speed = 64.69% 
'''
Solution-1:
Example: nums = [3,2,1,4]       target = 6
Step1) Create a dictionary and populate it with elements of nums as the key and their corresponding index as values.
        
    d = {
            3:0,
            2:1
            1:2
            4:3
        }
Step2) Traverse the array and check for every element, if complement (target-element) exists in dictionary. Also check,
the index of (target-element) is not same as that of element (using dictionary as we have saved index as values.)
Traversing the array:
#   i=0         3,2,1,4
                ^
    checking if (6-3) exists in dictionary?
    Yes it exists
    but d[6-3]==i (We are adding the same element to get the target which is invalid according to the question)

Step3) If we found a valid pair, then we return [i,d[complement]]
'''
'''
Time Complexity =  O(N)
Space Complexity = O(N)
'''

#Two-pass
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {v:i for i,v in enumerate(nums)}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in d and d[complement]!=i:
                return [i,d[complement]]

'''
Solution-2: Single Pass:
Instead of doing double passes (one pass while populating the dictionary and other while checking for complement),
We do this in Single Pass. that is, checking for complement while populating the dictionary.
Before inserting the element in dictionary, we check whether the complement already exists, if exists, we return both indexes
(index of current element and index of its complement) and if not exists, we insert the element in dictionary.
This way we wont have to check if the index of element and its complement is same or not.
'''

#Single Pass
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in d:
                return [d[complement],i]
            d[nums[i]]=i
