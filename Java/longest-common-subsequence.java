/*
* Problem Name: 1143. Longest Common Subsequence
* Link: https://leetcode.com/problems/longest-common-subsequence/
* Difficulty: Medium
* Concepts Involved: String, Dynamic Programming
*/

// Memoization
class Solution {
    public int longestCommonSubsequence(String s1, String s2) {
        int[][] dp = new int[s1.length()][s2.length()];
        for (int[] row: dp) Arrays.fill(row, -1);
        return helper(s1, s2, 0, 0, dp);
    }
    int helper(String s1, String s2, int i, int j, int[][] dp) {
        if (i == s1.length() || j == s2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1.charAt(i) == s2.charAt(j))
            return dp[i][j] = 1 + helper(s1, s2, i + 1, j + 1, dp);

        int left = helper(s1, s2, i + 1, j, dp);
        int right = helper(s1, s2, i, j + 1, dp);

        return dp[i][j] = Math.max(left, right);
    }
}




// Tabulation
class Solution {
    public int longestCommonSubsequence(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + dp[i - 1][j - 1];
                    continue;
                }
                int left = 0, right = 0;
                if (i > 0) left = dp[i - 1][j];
                if (j > 0) right = dp[i][j - 1];
                dp[i][j] = Math.max(left, right);
            }
        return dp[n - 1][m - 1];
    }
}




// Smarter way of tabulation to avoid boundary check:
class Solution {
    public int longestCommonSubsequence(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[][] dp = new int[n + 1][m + 1];	// extra space

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);

        return dp[n][m];
    }
}




// Space optimization:
class Solution {
    public int longestCommonSubsequence(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[] prev = new int[m + 1];

        for (int i = 1; i <= n; i++) {
            int[] cur = new int[m + 1];
            for (int j = 1; j <= m; j++)
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    cur[j] = 1 + prev[j - 1];
                else cur[j] = Math.max(prev[j], cur[j - 1]);
            prev = cur;
        }

        return prev[m];
    }
}