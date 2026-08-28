// LeetCode Problem 13: Roman to Integer
// Author: Tanzeela Fatima (@Fatima-progmmer)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int prev = 0;

        // Traverse from right to left
        for (int i = s.length() - 1; i >= 0; --i) {
            int current = roman[s[i]];

            if (current < prev)
                result -= current;
            else
                result += current;

            prev = current;
        }

        return result;
    }
};

