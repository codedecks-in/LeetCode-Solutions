/**
* Pow(x, n)
* Medium

Implement pow(x, n), which calculates x raised to the power n (i.e. xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25

Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= x^n <= 10^4

* Runtime: 84 ms, faster than 43.91% of JavaScript online submissions for Pow(x, n).
* Memory Usage: 39.1 MB, less than 5.12% of JavaScript online submissions for Pow(x, n).
*
*/

/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    return pow(x, n);
    
    function pow(x, n) {
        if (n == 0) {
            return 1.0;
        }
        const half = pow(x, parseInt(n / 2));
        if (n % 2 === 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
