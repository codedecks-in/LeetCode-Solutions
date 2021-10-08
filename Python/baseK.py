def sumBase(n: int, k: int) :
    """
Given an integer n (in base 10) and a base k, return the sum of the digits of n after converting n from base 10 to base k.
After converting, each digit should be interpreted as a base 10 number, and the sum should be returned in base 10.
TC : O(N)
SC : O(1)
n : int (integer base 10)
k : int (base to be converted to)
return value : int 
"""
    summation=0
    while n >= k :
        
        summation = summation + n%k
        n=n//k
    print(n)   
    return (summation + n)