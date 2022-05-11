/* https://leetcode.com/problems/maximal-rectangle/ */
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int longest_up[n][m];
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest_up[i][j] = 0;
                if (i == 0) {
                    longest_up[0][j] = matrix[0][j] - '0';
                } else if (matrix[i][j] == '1') {
                    longest_up[i][j] = longest_up[i - 1][j] + 1;
                }
                best = max(best, longest_up[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int min_up = longest_up[i][j];
                for (int c = j; c >= 0 && matrix[i][c] == '1'; c--) {
                    min_up = min(min_up, longest_up[i][c]);
                    best = max(best, (j - c + 1) * min_up);
                }
            }
        }
        return best;
    }
};

