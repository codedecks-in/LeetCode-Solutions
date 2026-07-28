/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

class Solution {
  bool isPalindrome(String s) {
    int left = 0;
    int right = s.length - 1;

    while (left < right) {
      while (left < right && !isAlphaNumeric(s[left])) {
        left++;
      }

      while (left < right && !isAlphaNumeric(s[right])) {
        right--;
      }

      if (s[left].toLowerCase() != s[right].toLowerCase()) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }

  bool isAlphaNumeric(String char) {
    final int code = char.codeUnitAt(0);

    return (code >= 48 && code <= 57) ||
        (code >= 65 && code <= 90) ||
        (code >= 97 && code <= 122);
  }
}
