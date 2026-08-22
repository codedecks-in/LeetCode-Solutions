#Time Complexity:   O(n)
#Space Complexity:  O(n)
#Speed: 96.63 %
#Memory: 62.57%

class Solution(object):
    def lengthOfLastWord(self, s):
        slists = s.strip()                     #to remove the whitespaces in the beginning and in end
        rial = slists.split(' ')               #taking the letters alone and making it a list
        return len(rial[-1])                   #returning the length of last element from the list