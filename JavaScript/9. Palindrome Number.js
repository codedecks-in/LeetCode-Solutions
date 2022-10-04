// https://leetcode.com/problems/palindrome-number/

// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.

// Example 1:
// Input: x = 121
// Output: true

// Example 2:
// Input: x = -121
// Output: false

// Example 3:
// Input: x = 10
// Output: false

var isPalindrome = function(x) {
    return x == x.toString().split('').reverse().join('');
  };