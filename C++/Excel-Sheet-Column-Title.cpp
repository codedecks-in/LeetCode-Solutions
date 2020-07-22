/*
 * Runtime - 0ms
 * Memory  - 5.8
 * LOGIC - simple maths
 * 
 */

class Solution {
public:
    string convertToTitle(int n) {
        string s="";
        while(n>26){
            int rem = n%26;
            n=n/26;
            if(rem==0){
                rem = 26;
                n--;
            }
            s.push_back('A'+(rem-1));
        }
        s.push_back('A'+n-1);
        reverse(s.begin(),s.end());
        return s;
    }
};
