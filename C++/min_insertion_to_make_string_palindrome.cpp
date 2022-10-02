// <!-- Leetcode 

// 1312. Minimum Insertion Steps to Make a String Palindrome

// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward. -->



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2+1,0), cur(n2+1,0);

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    cur[j] = 1 + prev[j-1];
                }

                else
                {
                    cur[j] = max(prev[j] , cur[j-1]);
                }
            }
            prev = cur;
        }

        return prev[n2];
    }

    string reverseStr(string str)
    {
        int n = str.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);

        return str;
    }

    int longestPalindromeSubseq(string s) {
        string t = reverseStr(s);
        return longestCommonSubsequence(s,t);
    }

    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    }
};