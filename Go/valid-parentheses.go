// LeetCode Problem 20: Valid Parentheses - Medium
package main

func isValid(s string) bool {
    stack := []rune{}
    pairs := map[rune]rune{')': '(', '}': '{', ']': '['}
    for _, char := range s {
        if pair, ok := pairs[char]; ok {
            if len(stack) == 0 || stack[len(stack)-1] != pair {
                return false
            }
            stack = stack[:len(stack)-1]
        } else {
            stack = append(stack, char)
        }
    }
    return len(stack) == 0
}
