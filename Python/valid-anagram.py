'''https://leetcode.com/problems/valid-anagram/'''
#brute
'''We keep count of every distinct character in a hashmap for both S & T.
Then compare if the count for each character in both is equal'''
from typing import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        S,T={},{}
        for i in range(0,len(s)):
            if s[i] in S.keys():
                S[s[i]]+=1 #updating count
            else:
                S[s[i]]=1 #recording a distinct element
        
        for i in range(0,len(t)):
            if t[i] in T.keys():
                T[t[i]]+=1
            else:
                T[t[i]]=1
        
        for i in range(0,len(t)):
            if t[i] in S.keys() and S[t[i]]==T[t[i]]:
                continue
            else:
                return False
        return True

#cocky way 1
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s)==Counter(t) #compares the count of every distinct element

#optimised in cocky way
'''We sort both the strings and compare them side by side.
Note that It is only space efficient but the one b4 is time efficient
also your interviewer may want you to write your own sort function for this'''
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s)==sorted(t)