//CPP BFS solution
//Time complexity O(V+E)
//Space Complexity O(V)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int m=prerequisites.size();
        vector<int>ans;
        vector<int>v(n,0);
        vector<vector<int>>g(n);
        
        
        for(int i=0;i<m;i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            v[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(!q.empty()){
            int j=q.front();
            q.pop();
            ans.push_back(j);
            cout<<j<<" ";
            c++;
            for(int i=0;i<g[j].size();i++){
                v[g[j][i]]--;
                //cout<<v[g[j][i]]<<" ";
                if(v[g[j][i]]==0){
                    
                    q.push(g[j][i]);
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        else{
            return ans;
        }
    }
};
