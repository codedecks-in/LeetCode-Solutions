#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    void solve(int n, int row, vector<string> &board,
               vector<bool> &cols, vector<bool> &d1, vector<bool> &d2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || d1[row - col + n - 1] || d2[row + col]) continue;

            board[row][col] = 'Q';
            cols[col] = d1[row - col + n - 1] = d2[row + col] = true;

            solve(n, row + 1, board, cols, d1, d2);

            board[row][col] = '.';
            cols[col] = d1[row - col + n - 1] = d2[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n), d1(2*n - 1), d2(2*n - 1);
        solve(n, 0, board, cols, d1, d2);
        return result;
    }
};

int main() {
    Solution sol;
    auto ans = sol.solveNQueens(4);
    for (auto &board : ans) {
        for (auto &row : board)
            cout << row << endl;
        cout << "------" << endl;
    }
}
