/** 
 *  Problem Name : Redundant Connection
 *  Concept Involved : Trees, Union Find
 * 
 *  Execution Time : 1 ms
 *  Memory Consumed : 39 mb
**/

class DUS{
    public int[] parent;
    public int n;
    
    DUS(int n){
        this.n = n;
        parent = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    public int find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    public void union(int u, int v){
        int pu = find(u);
        int pv = find(v);
        
        if(pu != pv){
            parent[pv] = pu;
        }
    }
}
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int[] res = new int[2];
        DUS dus = new DUS(edges.length+1);
        
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int pu = dus.find(u);
            int pv = dus.find(v);
            
            if(pu != pv){
                dus.union(u,v);    
            }
            else{
                res[0] = u;
                res[1] = v;
            }
        }
        
        return res;
    }
}