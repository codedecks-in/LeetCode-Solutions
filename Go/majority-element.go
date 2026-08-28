// LeetCode Problem 169: Majority Element - Medium
package main

func majorityElement(nums []int) int {
    count := 0
    candidate := 0
    for _, num := range nums {
        if count == 0 {
            candidate = num
        }
        if num == candidate {
            count++
        } else {
            count--
        }
    }
    return candidate
