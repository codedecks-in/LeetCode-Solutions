// LeetCode Problem 13: Roman to Integer - Medium
package main

func romanToInt(s string) int {
    romanMap := map[rune]int{
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    total := 0
    for i := 0; i < len(s); i++ {
        if i+1 < len(s) && romanMap[rune(s[i])] < romanMap[rune(s[i+1])] {
            total -= romanMap[rune(s[i])]
        } else {
            total += romanMap[rune(s[i])]
        }
    }
    return total
