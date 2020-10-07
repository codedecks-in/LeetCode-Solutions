'''
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
'''

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        from collections import defaultdict

        anagrams = defaultdict(list)
        for s in strs:
            anagrams[str(sorted(s))].append(s)

        return list(anagrams.values())

n=["eat", "tea", "tan", "ate", "nat", "bat"]
ans=Solution()
res=ans.groupAnagrams(n)
print(res)
