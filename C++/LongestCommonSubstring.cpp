class Solution
{
    string LCSubstr(string s1, string s2, vector<vector<int>> &t)
    {
        string ans = "";
        int n = s1.size();
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    if (t[i][j] > mx)
                    {
                        // For every possible LC substring, we check whether it's a palindrome or not.
                        // We know the size of the LC substring, so using "i" and "t[i][j]" we can find the substring after that we just need to check whether it's palindrome or not.
                        string temp = s1.substr(i - t[i][j], t[i][j]);
                        string temp2(temp.rbegin(), temp.rend());

                        if (temp == temp2)
                        {
                            mx = t[i][j];
                            ans = temp;
                        }
                    }
                }
                else
                {
                    t[i][j] = 0;
                }
            }
        }

        return ans;
    }

public:
    string longestPalindrome(string s1)
    {
        int n = s1.size();
        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));
        string s2(s1.rbegin(), s1.rend());
        return LCSubstr(s1, s2, t);
    }
};