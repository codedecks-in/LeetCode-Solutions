// C++ DFS + BFS Solution
// Time Complexity : O(V)
// Space Complexity : O(V)

class Solution {
public:
    vector<int> del_i = {1, 0, -1, 0};
    vector<int> del_j = {0, 1, 0, -1};

    bool checkWithinBounds(int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }

    void markIsland(vector<vector<int>>& A, int i, int j) {
        A[i][j] = -1;

        for (int k = 0; k < 4; ++k)
        {
            int next_i = i + del_i[k];
            int next_j = j + del_j[k];

            if (checkWithinBounds(next_i, next_j, A.size(), A[0].size()) && A[next_i][next_j] == 1)
                markIsland(A, next_i, next_j);
        }

    }

    int shortestBridge(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();

        // mark island of one group as -1
        int flag = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (A[i][j] == 1) {
                    flag = 1;
                    markIsland(A, i, j);
                    break;
                }
            }

            if (flag) break;
        }

        // queue that represent flips on a particular path
        queue<pair<int, int>> q;

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (A[i][j] == -1) {
                    q.push({i * r + j, 0});
                }
            }
        }

        while (!q.empty()) {
            int index = q.front().first;
            int i = index / r;
            int j = index % r;

            int flips = q.front().second;

            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int next_i = i + del_i[k];
                int next_j = j + del_j[k];
                int next_index = next_i * r + next_j;

                if (checkWithinBounds(next_i, next_j, r, c)) {
                    if (A[next_i][next_j] == 1) return flips;

                    if (A[next_i][next_j] == -1) continue;

                    q.push({next_index, flips + 1});

                    A[next_i][next_j] = -1;
                }
            }


        }
        return -1;

    }
};
