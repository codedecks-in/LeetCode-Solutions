class Solution
{
public:
    /*
    Uses classics Tree Re-rooting DP,
    Need to do 2 traversals: DFSes but 1 as Post Order and second as Pre-order
    
    When we move our root from parent to its child i, 
    count[i] points get 1 closer to root, n - count[i] nodes get 1 futhur to root.
    
    Time Complexity: O(N)  because both DFS visit all ndoes
    Space Compexity: O(N)  because of the resultant & helper subtree-node-count array
    
    */

    /* Post Order to update distances while going from parent to root
    To track a count of number of children in the subtree
    */
    void dfs1(int node, int parent, vector<int> &res, vector<int> &count, vector<vector<int>> &graph)
    {
        for (auto child : graph[node])
        {
            if (child == parent)
                continue;
            dfs1(child, node, res, count, graph);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }

    /* Pre order traversal style DFS, to update the result vector in direction of child -> parent */
    void dfs2(int node, int parent, vector<int> &res, vector<int> &count, vector<vector<int>> &graph, int n)
    {
        for (auto child : graph[node])
        {
            if (child == parent)
                continue;
            res[child] = res[node] - count[child] + n - count[child];
            dfs2(child, node, res, count, graph, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {

        vector<int> count(n, 1); //stores count of number of children, atleast 1 node, ie itself should be in count[node]
        vector<int> res(n, 0);   //Stores final distance sum for each node

        vector<vector<int>> graph(n);

        int u, v;

        // Constructing the graph from the given array
        for (int i = 0; i < edges.size(); ++i)
        {
            u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs1(0, -1, res, count, graph);
        dfs2(0, -1, res, count, graph, n);

        return res;
    }
};