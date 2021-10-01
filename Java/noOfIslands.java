class Solution {
    public int numIslands(char[][] grid) {
            if(grid.length==0)
                    return 0;
      ArrayList<ArrayList<Integer>> A=new ArrayList<ArrayList<Integer>>();
           int n=grid.length;
            int m=grid[0].length;
            for(int i=0;i<n;i++)
                    A.add(new ArrayList<Integer>(m));
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                     A.get(i).add(grid[i][j]-'0');
                    }
            }
            return findIslands(A,n,m);
    }
         static int findIslands(ArrayList<ArrayList<Integer>> A, int N, int M) {
int c=0;
if(A.size()==0)
return 0;
boolean[][] visited=new boolean[N][M];
for(int i=0;i<N;i++)
{
    for(int j=0;j<M;j++)
    {
        if(A.get(i).get(j)!=0 && visited[i][j]!=true)
        {
      c+=dfs(A,i,j,N,M,visited);
         
        }
    } 
}
return c;
}
  static int dfs(ArrayList<ArrayList<Integer>> A,int i,int j, int N, int M,boolean[][] visited)
{
    if(i<0 || j<0 || i>=N|| j>=M || A.get(i).get(j)==0 || visited[i][j]==true)
    return 0;
    
    visited[i][j]=true;
     dfs(A,i-1,j,N,M,visited);  
     dfs(A,i,j-1,N,M,visited); 
      dfs(A,i+1,j,N,M,visited); 
      dfs(A,i,j+1,N,M,visited);    
    return 1 ;
}
}
