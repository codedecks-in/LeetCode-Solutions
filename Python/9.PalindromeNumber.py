# compare reverse method
# simply reverse the input and check equality
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]

# double pointer method
# start at either end of the number and go inwards
# return false if a number doesn't match, otherwise it's a palindrome
class Solution:
    def isPalindrome(self, x: int) -> bool:
        arr = str(x)
        l, r = 0, len(arr) - 1
        while r > l:
            if arr[l] != arr[r]:
                return False
            l +=1
            r -= 2
        return True
