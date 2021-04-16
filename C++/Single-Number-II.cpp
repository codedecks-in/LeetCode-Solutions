// Leetcode URL: https://leetcode.com/problems/single-number-ii
/*
 * Runtime - 4ms
 * Memory  - 9.5
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0, b=0;
        for(int num: nums) {
            a = b & (a^num);
            b = a | (b^num);
        }
        return b;
    }
};