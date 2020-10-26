
//Problem Statement: Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Solution:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            // Bring all non zero numbers to the start of the array
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            } 
        }

        while(i<nums.size()){
            nums[i++] = 0;
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
