/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
class Solution
{
public:
    string sortSentence(string s)
    {
        int l = s.size(), i;
        string word;
        vector<string> map(10, "");
        for (i = 0; i < l; i++)
        {
            if (int(s[i]) >= 48 && int(s[i]) <= 57)
            {
                map[int(s[i]) - '1'] = word + " ";
                word = "";
                i++;
                continue;
            }
            word += s[i];
        }
        for (string x : map)
        {
            word += x;
        }
        word.pop_back();
        return word;
    }
};
// @lc code=end
