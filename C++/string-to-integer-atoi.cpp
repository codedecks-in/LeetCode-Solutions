#define UPPER_LIMIT 2147483647
#define LOWER_LIMIT -2147483648

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        bool negative = false;
        double result = 0;

        while(s[i] == ' ') i++;

        if(s[i] == '-'){
            negative = 1;
            i++;
        } else if (s[i] == '+') i++;

        while(s[i] >= '0' && s[i] <= '9'){
            result = result * 10 + (s[i] - '0');
            i++;
        }

        if (result > UPPER_LIMIT) return UPPER_LIMIT;
        if (result < LOWER_LIMIT) return LOWER_LIMIT;

        if(negative) return -result;
        return result; 
    }
};