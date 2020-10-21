class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //Topological sort
        Map<Integer,Integer> indegree = new HashMap<>();
        Map<Integer,List<Integer>> adj = new HashMap<>();
        for(int i = 0;i < numCourses;i++){
            adj.put(i,new ArrayList<>());
            indegree.put(i,0);
        }
        for(int i = 0;i < prerequisites.length;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj.get(v).add(u);
            indegree.put(u, indegree.get(u) + 1);
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0;i < numCourses;i++){
            if(indegree.get(i) == 0){
                q.add(i);
            }
        }
        int count = 0;
        while(!q.isEmpty()){
            int top = q.poll();
            indegree.remove(top);
            count++;
            for(Integer n:adj.get(top)){
                indegree.put(n,indegree.get(n) - 1);
                if(indegree.get(n) == 0){
                    q.add(n);
                }
            }
        }
        
        return count == numCourses;
    }
}