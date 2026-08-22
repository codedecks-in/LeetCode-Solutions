class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x!=0) {
            int pop = x % 10;
            x /= 10;
            // to check that it may not overflow integer range
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

//Solution 2

class Solution {
public:
    int reverse(int x) {
       long   r=0;      
         while(x!=0){
           long rev=x%10;
            r=r*10+rev;
            x=x/10;  
        }
         return (r > INT_MAX || r < INT_MIN) ? 0 : r;   
        } 
};
