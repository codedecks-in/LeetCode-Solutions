"""
3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring
without repeating characters.

Constraints:
- 0 <= s.length <= 5 * 10^4
- s consists of English letters, digits, symbols and spaces.
"""

def lengthOfLongestSubstring(s):
    """
    Approach: Sliding Window with HashMap
    Time Complexity: O(n)
    Space Complexity: O(min(m, n)) where m is charset size
    
    Use a sliding window approach with a hash map to track character positions.
    When we encounter a repeating character, move the window start.
    """
    char_index = {}
    max_length = 0
    start = 0
    
    for end in range(len(s)):
        if s[end] in char_index and char_index[s[end]] >= start:
            start = char_index[s[end]] + 1
        
        char_index[s[end]] = end
        max_length = max(max_length, end - start + 1)
    
    return max_length


# Test cases
if __name__ == "__main__":
    # Test case 1: String with repeating characters
    assert lengthOfLongestSubstring("abcabcbb") == 3  # "abc"
    
    # Test case 2: String with all unique characters
    assert lengthOfLongestSubstring("bbbbb") == 1  # "b"
    
    # Test case 3: String with mix of characters
    assert lengthOfLongestSubstring("pwwkew") == 3  # "wke"
    
    # Test case 4: Empty string
    assert lengthOfLongestSubstring("") == 0
    
    # Test case 5: Single character
    assert lengthOfLongestSubstring("a") == 1
    
    # Test case 6: All unique characters
    assert lengthOfLongestSubstring("abcdefg") == 7
    
    # Test case 7: Space character
    assert lengthOfLongestSubstring("au") == 2
    
    # Test case 8: Digits and symbols
    assert lengthOfLongestSubstring("0123456789") == 10
    
    print("All test cases passed!")
