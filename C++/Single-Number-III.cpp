// Problem URL: https://leetcode.com/problems/single-number-iii/
/*
 * Runtime - 8ms
 * Memory  - 10mb
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        // Get the XOR value of all the numbers in the vector
        for(int num: nums) xor_all ^= num;
        // xor_all will contain a^b, where a and b are repeated only once.
        // if value of a bit in xor is 1, then it means either a or b has 
        // 1 in that position, but not both. We can use this to find the answer.
        int setbit = 1;
        // Find the first position in xor_all where the value is 1
        while((setbit & xor_all) == 0) 
            setbit <<= 1;

        vector<int> result(2);

        // We basically split the numbers into two sets.
        // All numbers in first set will have a bit in the setbit position.
        // Second set of numbers, will have 0 in the setbit position.
        for(int num: nums) {
            if(num & setbit) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};