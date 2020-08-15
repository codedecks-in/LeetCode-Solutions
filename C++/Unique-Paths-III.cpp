class Solution {
private:
    int n;
    int m;
    int answer = 0;
    int required = 0;
    
    bool isValid(int x, int y) {
        return (0 <= x && x < n) && (0 <= y && y < m);
    }
    
    void dfs(vector<vector<int>> &grid, pair<int, int> s, pair<int, int> e, vector<pair<int, int>>& st, vector<vector<bool>> &used) {
        if (!st.empty() && st.back() == e && st.size() == required - 1) {
            ++answer;
            
            return;
        }
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};
        
        used[s.first][s.second] = true;
        for (int i = 0; i < 4; ++i) {
            if (isValid(s.first + dx[i], s.second + dy[i]) && (grid[s.first + dx[i]][s.second + dy[i]] == 0 || grid[s.first + dx[i]][s.second + dy[i]] == 2) && !used[s.first + dx[i]][s.second + dy[i]]) {
                used[s.first + dx[i]][s.second + dy[i]] = true;
                st.push_back({s.first + dx[i], s.second + dy[i]});
                dfs(grid, {s.first + dx[i], s.second + dy[i]}, e, st, used);
                st.pop_back();
                used[s.first + dx[i]][s.second + dy[i]] = false;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = (int) grid.size();
        m = (int) grid[0].size();
        
        pair<int, int> s;
        pair<int, int> e;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    s = {i, j};
                    ++required;
                }
                
                if (grid[i][j] == 2) {
                    e = {i, j};
                    ++required;
                }
                
                if (grid[i][j] == 0) {
                    ++required;
                }
            }
        }
        
        vector<pair<int, int>> st;
        vector<vector<bool>> used(n, vector<bool> (m, false));
        used[s.first][s.second] = true;
        dfs(grid, s, e, st, used);
        
        return answer;
    }
};