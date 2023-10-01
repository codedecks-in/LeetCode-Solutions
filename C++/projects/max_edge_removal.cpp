#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &graph, int node, vector<int> &visit, int &ans)
{

    int curcount = 0;
    visit[node] = 1;

    for (int i = 0; i < graph[node].size(); i++)
    {
        if (visit[graph[node][i]] != -1)
            continue;

        int subcount = dfs(graph, graph[node][i], visit, ans);

        if (subcount % 2 == 0)
            ans++;
        else
            curcount += subcount;
    }

    return curcount + 1;
}

int Maxedge(int N, vector<vector<int>> &B)
{

    vector<int> temp;
    vector<vector<int>> graph;

    for (int i = 0; i < N + 1; i++)
    {
        graph.push_back(temp);
    }

    for (int i = 0; i < B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }

    vector<int> visit(N + 1, -1);
    int ans = 0;

    dfs(graph, 1, visit, ans);
    return ans;
}


int main()
{
    int N = 5;
    vector<vector<int>> B = {{1, 2}, {1, 3}, {1, 4}, {2, 5}};
    cout << Maxedge(N, B);
    return 0;
}