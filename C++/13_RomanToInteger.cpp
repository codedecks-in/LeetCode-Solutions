// LeetCode Problem 13: Roman to Integer (Easy)
// Language: C++
// Contributor: Nihhaar0002
//
// Approach: Value Comparison (Single-Pass)
// ----------------------------------------
// Each Roman numeral has a fixed integer value:
//   I=1, V=5, X=10, L=50, C=100, D=500, M=1000
//
// Rule:
// - Normally we add values from left to right.
// - But when a smaller numeral appears before a larger numeral,
//   we must subtract the smaller value instead of adding it.
//
// Example:
//   IV => 4  (because 1 < 5 → subtract 1)
//   IX => 9  (because 1 < 10)
//   XL => 40 (10 < 50)
//
// Algorithm:
// - Traverse the string from left to right.
// - Add each value to sum.
// - If current value > previous value → subtract two times previous value
//   because it was added once earlier.
//
// Time Complexity:  O(N)
// Space Complexity: O(1)  (no extra data structures)

#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int current = 0, last = 0;
        int sum = 0;

        for(int i = 0; i < s.length(); i++){
            // Convert Roman char to integer value
            switch(s[i]){
                case 'I': current = 1; break;
                case 'V': current = 5; break;
                case 'X': current = 10; break;
                case 'L': current = 50; break;
                case 'C': current = 100; break;
                case 'D': current = 500; break;
                case 'M': current = 1000; break;
                default: current = 0;
            }

            sum += current;

            // Check for subtractive combination
            if(i != 0 && current > last)
                sum -= 2 * last;

            last = current;
        }

        return sum;
    }
};
