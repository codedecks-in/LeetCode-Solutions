class Solution {
    void findPaths(int[][] graph,int fromNode,List<Integer> path,List<List<Integer>> ans){
		//If fromNode has reached the last Node of graph , add this node to path and return
        if(fromNode==graph.length-1)
        {
            path.add(fromNode);
            ans.add(new ArrayList<Integer>(path));
            path.remove(path.indexOf(fromNode));
            return;
        }
		//Traverse for all nodes in list of fromNode
        for(int i=0;i<graph[fromNode].length;i++){
           if(path.size()==0)
               path=new ArrayList<Integer>();
			//Add the node and call for its list of reachable nodes 
            path.add(fromNode);
            findPaths(graph,graph[fromNode][i],path,ans);
            path.remove(path.size()-1);
        }
        return;
    }
    
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
		//Start from 0 node
        findPaths(graph,0,new ArrayList<Integer>(),ans);
        return ans;
    }
}
