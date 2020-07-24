#Time Complexity:   O(n)
#Space Complexity:  O(1)
#Speed: 62.81%
#Memory: 81.52%
'''
Xor Intuition: If different bits, result will be 1
               If same bits, results will be 0
Let's analyse few properties of Xor bitwise operation:
1) x^x = 0
    Example: 5^5 = 0
    Thing to note is, It works in collection also, For ex:
    In nums = [1,1,2,2,3,3,4,4], If we do complete xor of the list, result will be 0
    Code:
    
    xor = 0
    for i in nums:
        xor^=i
    print(xor)      # Prints 0

2) x^0 = x
    Example: 5^0 = 5
    Note:  If we have a list, which consists of every number repeating twice except a single number which is unique (does
    not repeat) then the complete xor of the list will give the unique number as output. (Since xor of all repeating number
    will be 0, and then 0^unique = unique )
    Example: nums = [1,1,2,2,999,3,3,4,4]
             ans = functools.reduce(lambda x,y:x^y, nums, 0)
             print(ans)         #Prints 999

    Now In the Given problem,
    [1,2,1,3,2,5]
    => There are two unique elements, so complete xor of list will result in xor of these two unique elements.
        Let them be x and y
    => So the complete xor of list will be:
        Example:   011
                 ^ 101
        result=    110
    => We will take any index in ans which is 1 (means that bit is diff in x and y) and partition the list into two groups
       based on whether that index bit is on(1) or off(0).
       In example we will take the rightmost bit which is 1, so the index is: 1
       Easiest way to do this:

                xor = xor^(-xor)    #gives a number in which only that particular bit is on.
                for n in nums:
                    if n & xor:         #If that bit in n is on
                        n belongs to group 1
                    else:
                        n belongs to group 2
                        
    => Xor of first group will give first unique element and xor of second group will give second unique element.
'''

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = reduce(lambda x,y: x^y, nums, 0)          #complete xor of list will result in xor of these two unique elements
        xor = xor&(-xor)
        first = second = 0
        for num in nums:
            if xor & num:
                first ^= num
            else:
                second ^= num
        return [first, second]