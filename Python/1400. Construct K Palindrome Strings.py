class Solution(object):
    def canConstruct(self, s, k):
        dict={char: 0 for char in "abcdefghijklmnopqrstuvwxyz"}

        if k==len(set(s)) or k== len(s):
            return True
        elif k>len(s):
            return False

        for c in s:
            dict[c]+=1

        count=0
        for c in dict.keys():
            if dict[c]%2!=0:
                count+=1

        if count>k:
            return False
        return True
