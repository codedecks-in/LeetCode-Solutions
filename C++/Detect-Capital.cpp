// Problem URL: https://leetcode.com/problems/single-number-iii/
/*
 * Runtime - 0ms
 * Memory  - 5.9mb
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_caps = 1;
        bool all_small = 1;
        bool first_letter_caps = isupper(word[0]);

        for(int i=1; i<word.length() && (all_caps | all_small); i++) {
            islower(word[i])? all_caps = 0: all_small = 0;
        }
        return (all_small | (first_letter_caps & all_caps));
    }
};