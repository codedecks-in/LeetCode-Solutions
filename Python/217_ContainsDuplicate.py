"""
217. Contains Duplicate
Easy

Given an integer array nums, return true if any value appears at least twice 
in the array, and return false if every element is distinct.

Constraints:
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
"""

def containsDuplicate(nums):
    """
    Approach: Using HashSet
    Time Complexity: O(n)
    Space Complexity: O(n)
    
    Uses a set to track seen numbers. If we encounter a number already in the set,
    we have a duplicate.
    """
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False


# Alternative approach using len comparison (more concise)
def containsDuplicate_v2(nums):
    """
    Approach: Set length comparison
    Time Complexity: O(n)
    Space Complexity: O(n)
    
    If there are duplicates, the set will have fewer elements than the list.
    """
    return len(nums) != len(set(nums))


# Test cases
if __name__ == "__main__":
    # Test case 1: Array with duplicate
    assert containsDuplicate([1, 2, 3, 1]) == True
    assert containsDuplicate_v2([1, 2, 3, 1]) == True
    
    # Test case 2: Array without duplicate
    assert containsDuplicate([1, 2, 3, 4]) == False
    assert containsDuplicate_v2([1, 2, 3, 4]) == False
    
    # Test case 3: Single element
    assert containsDuplicate([1]) == False
    assert containsDuplicate_v2([1]) == False
    
    # Test case 4: Two elements with duplicate
    assert containsDuplicate([1, 1]) == True
    assert containsDuplicate_v2([1, 1]) == True
    
    # Test case 5: Duplicate at end
    assert containsDuplicate([99, 99]) == True
    assert containsDuplicate_v2([99, 99]) == True
    
    print("All test cases passed!")
