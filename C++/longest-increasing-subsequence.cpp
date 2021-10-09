/*
Difficulty: medium
runtime: 8ms
Time Complexity: O(NlogN), where N is length of array
Space Complexity: O(1)

Q - 300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

----

Explanation:
We will extend the current sequence whenever we find an element which is greater than previously selected element.

If we find an element which is greater than peviously selected element, we apply binary search 
over sequence formed till now and replace the first element greater than or equal to current element 

Finally the length of seqeunce formed at end will be the maximum length of increasing subsequence.

A detailed explanation of this solution can be found here - 
https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int len = 0;   // length of LIS
        for(auto cur : A) 
            if(len == 0 || A[len-1] <= cur) A[len++] = cur;             // extend
            else *lower_bound(begin(A), begin(A) + len, cur) = cur;     // replace
        return len;
    }
};
