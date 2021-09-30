/*
ProblemLink : https://leetcode.com/problems/redundant-connection/

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.
*/

class Solution {
public:
    int find(int v,vector<int>& parent){
        if(parent[v]==-1){
            return v;
        }
        return find(parent[v],parent);
    }
    void Union(int x,int y,vector<int>& parent){
        parent[x]=y;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        vector<int> parent(V+1,-1);
        int v1,v2;
        for(auto x:edges){
            int fromP = find(x[0],parent);
            int toP = find(x[1],parent);
            if(fromP==toP){
                v1=x[0];
                v2=x[1];
            }
            else{
                Union(fromP,toP,parent);
            }
        }
        vector<int> ans;
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
