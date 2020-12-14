/**
Approach is to use AP formula
Sum = n/2(a+l)

where sum will be sum of all elements
n will be number of elements
a will be minimum element
l will be maximum element

if both LHS & RHS values are equal then return true, else false.
*/
class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int n = arr.length;
        
        double sumOfMaxAndMin = 0;
        
        int sum = arr[0];
        int max = arr[0];
        int min = arr[0];
        
        // Traverse the array and find out sum, max & min
        for (int i=1; i<n; i++){
            sum += arr[i];
            
            if (max < arr[i]){
                max = arr[i];
            }
            
            if (arr[i] < min){
                min = arr[i];
            }
        }
        
        // add max & min -> also they are first & last element
        sumOfMaxAndMin = max + min;
        
        // multiply above value with n
        sumOfMaxAndMin *= n;
        
        // divide above value with 2
        sumOfMaxAndMin /= 2;
        
        if (sum == sumOfMaxAndMin){
            return true;
        }
        
        return false;
    }
}
