#   program for TWO Number Sum

#   naive approach using two for loops
def twoNumberSum(arr : list, target : int) -> list : 
    result = list()
    for i in range(len(arr)) : 
        for j in range(i+1, len(arr)) : 
            if arr[i]+arr[j] == target : 
                result.append((arr[i],arr[j]))
    return result

#   this approach uses the concept of hash table for this problem
def two_number_sum(arr : list, target : int) -> list : 
    nums = list();result = list()
    for el in arr : 
        if target-el in nums : 
            result.append((el, target-el))
        else : 
            nums.append(el)
    return result

#   this approach is called as sliding window algorithm and takes O(nlogn) time complexity
def SumOfTwo(arr, target) : 
    result = list()
    arr.sort()
    left = 0;right=len(arr)-1
    while(left < right) : 
        if arr[left] + arr[right] == target : 
            result.append((arr[left], arr[right]))
            left+=1;right-=1
        elif arr[left] + arr[right] < target : 
            left+=1
        elif arr[left] + arr[right] > target : 
            right-=1

    return result

if __name__ == '__main__' : 
    print(SumOfTwo([3,5,-4,8,11,1,-1,6], 10))   
    # -4 -1 1 3 5 6 8 11 