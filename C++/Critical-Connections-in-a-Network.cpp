// C++ Implemntation of Tarjan's Algorithm to find bridges in an undirected graph
// Time Complexity : O(V + E)
// For explanation, check: https://www.geeksforgeeks.org/bridge-in-a-graph/

class Solution {
public:
    int steps = 0;

    vector<int> parent;
    vector<vector<int>> adjacent_matrix;

    vector<int> steps_taken;
    vector<int> min_steps_taken;

    vector<bool> visited;

    void initParent(int& n) {
        for (int i = 0; i <= n; ++i)
        {
            parent.push_back(i);
        }
        adjacent_matrix = vector<vector<int>>(n);

        steps_taken = vector<int>(n);
        min_steps_taken = vector<int>(n);

        visited = vector<bool>(n);
    }

    void addEdge(int& x, int& y) {
        adjacent_matrix[x].push_back(y);
        adjacent_matrix[y].push_back(x);
    }

    void dfs(int& vertex, vector<vector<int>>& ans) {
        visited[vertex] = true;

        steps_taken[vertex] = min_steps_taken[vertex] = steps++;

        for (auto adj_vertex : adjacent_matrix[vertex]) {
            if (!visited[adj_vertex]) {
                parent[adj_vertex] = vertex;

                dfs(adj_vertex, ans);

                min_steps_taken[vertex] = min(min_steps_taken[vertex], min_steps_taken[adj_vertex]);

                // check if the edge is crticial for network or not
                if (min_steps_taken[adj_vertex] > steps_taken[vertex]) {
                    ans.push_back({vertex, adj_vertex});
                }

            } else {
                if (parent[vertex] != adj_vertex) {
                    min_steps_taken[vertex] = min(min_steps_taken[vertex], steps_taken[adj_vertex]);
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        initParent(n);

        for (auto connection : connections) {
            addEdge(connection[0], connection[1]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (visited[i]) continue;
            dfs(i, ans);
        }

        return ans;
    }
};
