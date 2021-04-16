// Problem URL: https://leetcode.com/problems/single-number-iii/
/*
 * Runtime - 0ms
 * Memory  - 5.8mb
 */

class Solution {
public:
    int findComplement(int num) {
        int inv = 0, iter = 0;
        int reminder;
        while(num) {
            inv = inv | ((1 - (num % 2))<<iter);
            num /= 2;
            iter++;
        }
        return inv;
    }
};

