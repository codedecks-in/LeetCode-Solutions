/**
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
 */

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  var max = 0;
  var head = 0;
  var n = s.length;
  var i = 0;
  while (i < n - max / 2) {
    var lo = i;
    while (i < n && s[i] === s[lo]) {
      i++;
    }
    var hi = i - 1;
    while (lo >= 0 && hi < n && s[lo] === s[hi]) {
      lo--;
      hi++;
    }
    if (hi - lo - 1 > max) {
      max = hi - lo - 1;
      head = lo + 1;
    }
  }
  return s.slice(head, head + max);
};
