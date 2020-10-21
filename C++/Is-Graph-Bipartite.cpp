//CPP BFS solution
//Time complexity O(V+E)
//Space Complexity O(V)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>v(n,false);
        vector<int>c(n,-1);
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(v[i]||graph[i].size()==0){
                continue;
            }
            q.push(i);
            v[i]=true;
            c[i]=1;
            while(!q.empty()){
                int j=q.front();
                q.pop();
                for(int k=0;k<graph[j].size();k++){
                    if(c[graph[j][k]]==-1){
                        c[graph[j][k]]=1-c[j];
                        q.push(graph[j][k]);
                        v[graph[j][k]]=true;
                    }
                    else if(c[j]==c[graph[j][k]]){
                        return false;
                    }
                }
            }
            
        }
        return true;
        
        
    }
};