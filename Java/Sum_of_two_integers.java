// Time-Complexity:-  -> O(1) constant as 32 is the number of bits at most we will have to bit shift until carry is zero.
// Space-Complexity:- O(1)


class Solution {
    public int getSum(int a, int b) {
    
     int xor=a ^ b;
        int carry= a & b;
        if(carry == 0)
            return xor;
        else
           return getSum(xor,carry<<1);
    }
}
