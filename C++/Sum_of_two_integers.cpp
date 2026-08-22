// Time-Complexity:-  -> O(1) constant as 32 is the number of bits at most we will have to bit shift until carry is zero.
// Space-Complexity:- O(1)

class Solution {
public:
    int getSum(int a, int b) {
        if(a==0 || b==0){
            return a^b;
        }
        return getSum(a^b , (unsigned(a&b) <<1));
    }
};
