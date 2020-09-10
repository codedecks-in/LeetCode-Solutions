#Submission: 95.83%
'''
Step 1)     We will generate a array and fill it with 0 or 1
            0 If the letter at corresponding index in word is lower.
            1 if the letter at corresponding index in word is upper.
Example:    USA => 111
            Is => 10
            country => 0000000
step 2)     Word will be valid if:
            a) When word starts with Capital and remaining all are small => Then the number for such word will be 10.....0
                    To make 10...0 we will do:      1<<(size-1)
            b) When all are lower => Then the number will be 00...0
                    To make 00...0 we will do:      0<<(size-1)
            c) When all are capital => Then the number will be 1....1
                    To make 1...1 we will do:       (1<<size)-1
Step 3)     If the number generated in step 1 matches any of the valid numbers, Then the word is valid.
'''
'''
Time Complexity: O(n)
Space Complexity: O(1)
'''
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        num = 0
        size = len(word)

        #Generating the number
        for i in range(size):
            num = num*10
            if word[i].isupper():
                num+=1
        num = int(str(num),2)

        #Checking if it matches any of the valid number
        if num==(1<<(size-1)) or num==(0<<(size-1))  or num==((1<<size)-1):
            return True
        return False