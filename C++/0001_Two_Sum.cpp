// LeetCode 1 - Two Sum
// Difficulty: Easy
// Tags: Array, HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)
// Link: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value → index
        
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            
            // Check if remaining exists in map
            if (mp.find(remaining) != mp.end()) {
                return {mp[remaining], i};
            }
            
            mp[nums[i]] = i;
        }
        return {};
    }
};
