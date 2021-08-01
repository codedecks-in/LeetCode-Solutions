"""
LeetCode submission result:
 (987 / 987 test cases passed. \ Status: Accepted \ Runtime: 76 ms \ Memory Usage: 14.4 MB) 
 - available at: https://leetcode.com/submissions/detail/531509506/ 
"""

class Solution:
    def lengthOfLongestSubstring(self, string: str) -> int:

        # Creating a charactersCountDict to store count of characters in the current 
        charactersCountDict = {}
        
        # declaring variables to mark the Starting Index as well as Maximum Length of any contiguous substring without recurring characters achieved
        currentStartingIndex = maxLength = 0

        # Iterating through all indices of the string, one by one, while analyzing string between 'currentStartingIndex' and this ending 'index'.
        for index in range(len(string)):
            # In case string character at this index already exists between string[currentStartingIndex:index], then removing the starting of string from currentStartingIndex considered to remove any repeated characters in the considered string
            while string[index] in charactersCountDict:
                charactersCountDict[string[currentStartingIndex]] -= 1          # Reducing the string character count of string[currentStartingIndex] character so as to eliminate it from current string (in the considered sliding window)
                if charactersCountDict[string[currentStartingIndex]] < 1: charactersCountDict.pop(string[currentStartingIndex])     # If current count of this character goes below 1, that means this character no longer exists in the substring, therefore the character key is removed from charactersCountDict counter dictionary
                currentStartingIndex += 1                                       # Shifting the currentStartingIndex one step ahead
            
            # Now that the while loop has completed, it is assured that this character is not included in the substring string[currentStartingIndex:index], therefore we can safely insert it in string[currentStartingIndex:index+1] (last index excluded in the string slice)
            charactersCountDict[string[index]] = 1

            maxLength = max(maxLength, index-currentStartingIndex+1)    # Assessing maxLength to be maximum of current substring with unique character and maximum length achieved at any point of time while carefully sliding the limits

        return maxLength            # Finally, returning the desired maximum length of contiguous substring that has no repeating characters