#include <vector>
#include <queue>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int m = board.size();
        int n = board[0].size();
        
        // Directions for moving up, down, left, right
        std::vector<std::pair<int, int>> directions = {
            {1, 0},  // down
            {0, 1},  // right
            {0, -1}, // left
            {-1, 0}  // up
        };

        // BFS function to mark all connected 'O's
        auto bfs = [&](int startY, int startX) {
            std::queue<std::pair<int, int>> q;
            q.push({startY, startX});
            board[startY][startX] = 'E'; // Mark as visited with 'E'

            while (!q.empty()) {
                auto [y, x] = q.front();
                q.pop();

                for (const auto& dir : directions) {
                    int newY = y + dir.first;
                    int newX = x + dir.second;

                    if (newY >= 0 && newY < m && newX >= 0 && newX < n && board[newY][newX] == 'O') {
                        board[newY][newX] = 'E'; // Mark as visited
                        q.push({newY, newX});    // Add to queue
                    }
                }
            }
        };

        // Check all edge 'O's
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') bfs(0, i);        // Top row
            if (board[m - 1][i] == 'O') bfs(m - 1, i); // Bottom row
        }

        for (int j = 1; j < m - 1; ++j) {
            if (board[j][0] == 'O') bfs(j, 0);        // Left column
            if (board[j][n - 1] == 'O') bfs(j, n - 1); // Right column
        }

        // Update the board: 'O's not connected to the edges become 'X', and 'E's back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Flip 'O's to 'X's
                } else if (board[i][j] == 'E') {
                    board[i][j] = 'O'; // Restore 'E's back to 'O's
                }
            }
        }
    }
};