# split on whitespace and reverse the order of the words
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
