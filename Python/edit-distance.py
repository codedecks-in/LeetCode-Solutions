'''
Speed:              99.48%
Memory:             81.78%
Time Complexity:    O(N*M) where N = len(s1) and M = len(s2)
'''
class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        @lru_cache(None)
        def editdistance(i,j,s1=s1,s2=s2):
            if not i:
                return j
            if not j:
                return i
            if s1[i-1]==s2[j-1]:
                return editdistance(i-1,j-1)
            else:
                return 1 + min(editdistance(i-1,j),editdistance(i,j-1),editdistance(i-1,j-1))
                # Insert,Delete,replace
        return editdistance(len(s1),len(s2),s1,s2)