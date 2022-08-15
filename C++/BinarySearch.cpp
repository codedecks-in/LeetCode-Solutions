//Problem Statement: Binary Search

// Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


//Solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int si=0, ei=nums.size()-1;
        
        while(si <= ei) {
            // index of the middle element
            int mid = si + (ei-si)/2; 

            // found target element
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) { // target on right side of middle element
                si=mid+1; // si += 1;
            } else { // target on left side of middle element
                si=mid-1; // ei -= 1;
            }
        }

        // target element not present in given array
        return -1;
    }
};

// Time Complexity: O(log(n))

