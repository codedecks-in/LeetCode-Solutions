class Solution
{
public:
    string reverseWords(string s)
    {
        // Marking the start and end of the word in the sentence
        int start = 0, end = 0;
        int n = s.length();
        while (start < n)
        {
            while (end < n && s[end] != ' ')
            {
                end++;
            }
            // Reverse the word once we encounter a space
            reverse(s.begin() + start, s.begin() + end);
            // start again from the new Word
            start = end + 1;
            end = start;
        }
        return s;
    }
};