class Solution {
private:
    bool valid(int n, int m, int x, int y) {
        return (0 <= x && x < n) && (0 <= y && y < m);
    }
    
    string convert(vector<vector<int>> &c, int n, int m) {
        string s;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                s += c[i][j] + '0';
            }
        }
        
        return s;
    }
    
    int get(string s, int i, int j, int n, int m) {
        return s[i * m + j] - '0';
    }
    
    void set(string &s, int i, int j, int val, int n, int m) {
        s[i * m + j] = val + '0';
    }

public:
    int minFlips(vector<vector<int>>& c) {
        int n = c.size();
        int m = c[0].size();
        
        map<string, int> dp;
        map<string, bool> used;
    
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        string cToNum = convert(c, n, m);
        string zero(n * m, '0');
        
        if (cToNum == zero) {
            return 0;
        }
        
        queue<string> q;
        q.push(cToNum);
        
        dp[cToNum] = 0;
        
        while (!q.empty()) {
            string a = q.front();
            q.pop();
            
            used[a] = true;
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    string b = a;
                    
                    set(b, i, j, 1 - get(b, i, j, n, m), n, m);
                    
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        
                        if (valid(n, m, x, y)) {
                            set(b, x, y, 1 - get(b, x, y, n, m), n, m);
                        }
                    }
                    
                    if (!used[b]) {
                        q.push(b);
                        dp[b] = dp[a] + 1;
                        
                        if (b == zero) {
                            return dp[b];
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};