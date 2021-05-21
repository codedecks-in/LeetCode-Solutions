// Time-Complexity:- O(1)
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
