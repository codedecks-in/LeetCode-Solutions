/*
Problem:
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is palindrome while 123 is not.

Example 1:

Input: x = 121
Output: true

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Constraints:

-2^31 <= x <= 2^31 - 1
*/

/*
Difficulty level: Easy
*/

/*
Approach:
first we will find out the reverse of the given number.
for getting reverse number we will use the modulo (%) operator.
Once we obtain the reverse number we will compare it with the given number.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        long long int sum = 0, temp , r;
        temp = x ;
        while(x > 0){
            r = x % 10 ;
            sum = sum *10 + r ;
            x /= 10;
        }
        if(temp == sum){
            return true;
        }
        else return false;
    }
};
