
//Problem Statement: Excel Sheet Column Number

// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...

//Solution:
class Solution {
public:
    int titleToNumber(string s) {
        
        int power=0, colnum=0;

        while(!s.empty()) {

            colnum += (s[s.size()-1] - 'A' + 1)*pow(26, power);
            power++;
            s=s.substr(0, s.size()-1);

        }

        return colnum;
    }
};

//Complexity: O(n)
