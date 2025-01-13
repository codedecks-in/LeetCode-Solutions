class Solution
{
public:
    int minimumLength(string s)
    {
        // Step 1: Initialize a frequency map to count occurrences of each
        // character
        unordered_map<char, int> charFreq;

        // Step 2: Count the frequency of each character in the string
        for (char currChar : s)
        {
            charFreq[currChar]++;
        }

        // Step 3: Calculate the total length after deletions count
        int totalLen = 0;
        for (const auto &entry : charFreq)
        {
            // If frequency is even, we can remove all occurrences
            // If frequency is odd, we can remove all but one occurrence
            totalLen += (entry.second % 2 == 0) ? 2 : 1;
        }

        // Step 4: Return the minimum length after deletions count
        return totalLen;
    }
};