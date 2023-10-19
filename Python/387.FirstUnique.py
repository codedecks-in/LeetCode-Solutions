class Solution:
    def firstUniqChar(self, s: str) -> int:
        # count occurrences of each character
        memo = dict()
        for i in s:
            if not i in memo:
                memo[i] = 1
            else:
                memo[i] += 1

        # return the first single occurrence
        for i in memo:
            if memo[i] == 1:
                return s.index(i)

        # otherwise there were no single occurrences
        return -1
