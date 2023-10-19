# pop each letter out of the pool as we use them
# if there are none available, it's false, otherwise true
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        pool = list(magazine)
        for c in ransomNote:
            if c in pool:
                pool.remove(c)
            else:
                return False
        return True
