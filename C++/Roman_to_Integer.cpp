#include <string>

/*** 13. Roman to Intege (Easy)***/

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    int romanToInt(string s) {
        int current = 0, last =0;
        int sum=0;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case 'I':
                    current = 1;
                    break;
                case 'V':
                    current = 5;
                    break;
                case 'X':
                    current = 10;
                    break;
                case 'L':
                    current = 50;
                    break;
                case 'C':
                    current = 100;
                    break;
                case 'D':
                    current = 500;
                    break;
                case 'M':
                    current = 1000;
                    break;
                default:
                  break;
            }
            sum+=current;
            /*
            I can be placed before V (5) and X (10) to make 4 and 9. 
            X can be placed before L (50) and C (100) to make 40 and 90. 
            C can be placed before D (500) and M (1000) to make 400 and 900
            */
            if(i!=0&&current>last)
                sum-=2*last;
            last = current;
            
        }
        return sum;
    }
};