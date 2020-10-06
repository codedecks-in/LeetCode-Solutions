"""
15. 3Sum
Medium

8121

881

Add to List

Share
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
"""

def sum_of_three(arr, target=0) : 
    result = list()
    arr.sort()
    
    for i in range(len(arr)-2) : 
        left = i+1;right=len(arr)-1

        while left < right : 
            current_sum = arr[i] + arr[left] + arr[right]
            if current_sum == target : 
                result.append((arr[i], arr[left], arr[right]))
                left+=1
                right-=1
            elif current_sum < target : 
                left += 1
            elif current_sum > target :
                right -= 1
    else : 
        print("Dont with the loop")
    return result

if __name__ == '__main__' : 
    print(sum_of_three([3,5,-4,8,11,1,-1,6]))
