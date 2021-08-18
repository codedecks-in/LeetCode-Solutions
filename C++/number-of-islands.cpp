class Solution {
public:
    bool visited[300][300];
    int r[4] = {-1,0,0,1};
    int c[4] = {0,-1,1,0};
    bool val(int row,int col,vector<vector<char>>& grid,int M,int N)
    {
        return (row<M && col<N && row>=0 && col>=0 && !visited[row][col] && grid[row][col]=='1');
    }
    void dfs(int i,int j,vector<vector<char>>& grid, int M, int N)
    {
        visited[i][j] = true;
        for(int a=0;a<4;a++)
        {
                int row = i + r[a];
                int col = j + c[a];
                if(val(row,col,grid,M,N))
                {
                    dfs(row,col,grid,M,N);
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(visited,0,sizeof(visited));
        int island_count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid,m,n);
                    island_count++;
                }
            }
        }
        return island_count;
    }
};