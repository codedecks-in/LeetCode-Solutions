//CPP DFS SOLUTION

// Problem statement: Return the no of mins required to inform all employees about the urgent news

class Solution {
public:
    vector<int> adjList[100005];
    
    int dfs(int headID, vector<int>& informTime)
    {
        int maxTime=0;
        for(auto employee : adjList[headID])
        {
            maxTime=max(maxTime, dfs(employee, informTime));
        }
        return informTime[headID] + maxTime;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adjList[manager[i]].push_back(i);
        }
        return dfs(headID, informTime);
    }
};

//Space Complexity: O(N)
//Time Complexity : O(N)