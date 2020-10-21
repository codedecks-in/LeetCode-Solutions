// C++ Union Find Solution
// Time Complexity: O(V)
// Space Complexity: O(V)

class Solution {
public:
    vector<int> parent;
    void initParent(int n) {
        for (int i = 0; i <= n; ++i)
        {
            parent.push_back(i);
        }
    }

    int find_parent(int& x) {
        if (parent[x] == x) return x;
        parent[x] = find_parent(parent[x]);
        return parent[x];
    }

    bool unionEdge(int& x, int& y) {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);

        if (parent_x == parent_y) return false;

        if (parent_x > parent_y) parent[parent_x] = parent_y;
        else parent[parent_y] = parent_x;

        return true;
    }

    // map to store the index of first occurence of parent of the current index
    unordered_map<int, int> rows, cols;

    int removeStones(vector<vector<int>>& stones) {
        initParent(stones.size());

        for (int k = 0; k < stones.size(); k++) {
            int i = stones[k][0], j = stones[k][1];
            int par_i = INT_MAX, par_j = INT_MAX;

            if (rows.find(i) == rows.end()) rows[i] = k;
            else par_i = rows[i];

            if (cols.find(j) == cols.end()) cols[j] = k;
            else par_j = cols[j];

            if (par_i != INT_MAX)
                unionEdge(par_i, k);

            if (par_j != INT_MAX)
                unionEdge(par_j, k);
        }

        // ans represent number of disjoint sets
        int ans = 0;
        rows.clear(); cols.clear();
        unordered_set<int> uniq_parents;

        for (int k = 0; k < stones.size(); k++) {
            int par_i = find_parent(k);

            if (uniq_parents.find(par_i) == uniq_parents.end()) {
                ans++;
                uniq_parents.insert(par_i);
            }
        }

        return stones.size() - ans;
    }
};