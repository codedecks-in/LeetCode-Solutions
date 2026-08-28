// LeetCode Problem 5: Longest Palindromic Substring - Medium
package main

func longestPalindrome(s string) string {
    if len(s) < 2 {
        return s
    }
    start, maxLen := 0, 1
    for i := 0; i < len(s); i++ {
        // Odd length palindromes
        len1 := expandAroundCenter(s, i, i)
        // Even length palindromes
        len2 := expandAroundCenter(s, i, i+1)
        len := max(len1, len2)
        if len > maxLen {
            maxLen = len
            start = i - (len-1)/2
        }
    }
    return s[start : start+maxLen]
}

func expandAroundCenter(s string, left, right int) int {
    for left >= 0 && right < len(s) && s[left] == s[right] {
        left--
        right++
    }
    return right - left - 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
