"""1200. Minimum Absolute Difference
Easy

382

25

Add to List

Share
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
"""

def smallestDifference(arr1 : list, arr2 : list) : 
    arr1.sort();arr2.sort()
    i = 0;j = 0

    smallest = float("inf");current=float("inf")
    smallestPair = list()
    
    while i < len(arr1) and j < len(arr2) : 
        fnum = arr1[i];snum = arr2[j]
        
        if fnum < snum : 
            current = snum - fnum
            i += 1
        elif snum < fnum : 
            current = snum - fnum
            j += 1
        else : 
            return [fnum, snum]

        if current < smallest : 
            smallest = current
            smallestPair.append((fnum, snum))
            


if __name__ == '__main__' : 
    print(smallestDifference([12,3,45,6], [2,4,3,5]))