// Approach:
// 1. Store Roman numeral values in a hash map.
// 2. Traverse the string from right to left.
// 3. If current value >= previous value → add it, else subtract it.
// 4. Update previous value each iteration.
// 5. Return the final result.

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> roman{
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        char prev = s.back();
        ans += roman[prev];

        for (int i = s.size() - 2; i >= 0; i--) {
            char ch = s[i];
            if (roman[ch] >= roman[prev]) ans += roman[ch];
            else ans -= roman[ch];
            prev = ch;
        }
        return ans;
    }
};
//Time Complexity: O(N) where N is length of string
//Space Complexity: O(1) Only unordered_map is used of size 5 to store roman literals
