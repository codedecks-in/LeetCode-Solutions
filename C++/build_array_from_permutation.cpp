class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        /* For solving the question in 0(1) space complexity,
        the whole idea is to store 2 numbers at one
        place(however we can only store one value at one position
        so we need to use 
        some formula), since we need to retain the previous number 
        and update the value with the new one 
        
            For example:
            input array: {1,0}
            so I simple used this equation nums[i]+=n*(nums[nums[i]]%n)
            It made my array {1,2}, so after dividing by 2 it resulted in {0,1} which is the correct answer.
            Space Complexity: O(1)
            Time Complexity: O(N).*/

        
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = nums[i] + (nums[nums[i]]%n)*n;  /* Divident = Divisor*Quotient + Remainder */          
        }
        for(int i = 0 ; i < nums.size() ;i++){
            nums[i] = nums[i]/n;    /*Gives new value*/
        }
        return nums;
    }
};
