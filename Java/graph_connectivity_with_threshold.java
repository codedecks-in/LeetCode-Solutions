/** 
 *  Problem Name : Graph Connectivity with Threshold
 *  Concept Involved : Disjoint Union Set, Seive
 * 
 *  Execution Time : 16 ms
 *  Memory Consumed : 92.7 mb
 * 
*/
class Solution {
    public static class Dus {
        int[] parent;
        int n;

        Dus(int n) {
            this.n = n;
            parent = new int[n];
            for (int i = 1; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int u) {
            if (u != parent[u]) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        public void union(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu != pv) {
                parent[pv] = pu;
            }
        }
    }
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
        ArrayList<Boolean> res = new ArrayList<>();
        Dus dus = new Dus(n+1);

        for(int i=1; i<=n; i++){
            for(int j=2*i; j<=n; j+=i){
                if(i > threshold){
                    dus.union(i,j);
                }
            }
        }

        for(int i=0; i<queries.length; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int pu = dus.find(u);
            int pv = dus.find(v);

            if(pu == pv){
                res.add(true);
            }
            else{
                res.add(false);
            }
        }

        return res;    
    }
}