//Problem Statement: Course Schedule

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Solution:
// approach used to solve the problem: detect cycle in directed graph
// if a back edge exists in the graph, it implies that there is a cycle, thus it is not possible to finish all the courses

class Solution {
public:
    
    // helper function
    bool dfs(vector<vector<int>>& adjlist, vector<int>& visited, int i) {
        
        // base condition
        if(visited[i]==1) return false;
        visited[i]=1; // mark as being visited
    
        for(int a:adjlist[i]) {
            if(!dfs(adjlist, visited, a)) // dfs(adjlist, visited, a) == false
                return false; 
        }
        
        visited[i] = 2; // mark as visited
        return true; 
    }
    
    
    bool canFinish(int numc, vector<vector<int>>& prereq) {

        // numc: numCourses
        // prereq: prerequisites
        
        // create adjacency list
        vector<vector<int>> adjlist(numc, vector<int>());
        for(vector<int>& p:prereq)
            adjlist[p[0]].push_back(p[1]);
    
        vector<int> visited(numc, 0); 
        // unvisited: 0
        // being visited: 1
        // completely visited: 2
        for(int i=0; i<numc; i++) {
            if(visited[i]==0 && !dfs(adjlist, visited, i))
                return false;
        }
        
        return true;
    }
    
};
