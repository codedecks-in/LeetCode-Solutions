/** 
 *  Problem Name : Path with Minimum Effort
 *  Concept Involved : Graphs, Dijkstra's Shortest Path
 * 
 *  Execution Time : 1229 ms
 *  Memory Consumed : 39.4 mb
 * 
*/
class Point{
    int x;
    int y;
    int height;

    public Point(int x, int y, int height){
        this.x = x;
        this.y = y;
        this.height = height;
    }
}
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;

        int sx = 0;
        int sy = 0;

        int[][] dist = new int[n][m];
        int[][] vis = new int[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        dist[sx][sy] = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int px = -1;
                int py = -1;
                int mdist = Integer.MAX_VALUE;

                for(int k=0; k<n; k++){
                    for(int l=0; l<m; l++){
                        if(mdist > dist[k][l] && vis[k][l]==0){
                            mdist = dist[k][l];
                            px = k;
                            py = l;
                        }
                    }
                }

                vis[px][py] = 1;
                Point cpoint = new Point(px, py, heights[px][py]);

                if(cpoint.x > 0){
                    int lx = cpoint.x - 1;
                    int ly = cpoint.y;
                    if(vis[lx][ly] == 0){
                        dist[lx][ly] = Math.min(dist[lx][ly], Math.max(dist[cpoint.x][cpoint.y], Math.abs(cpoint.height - heights[lx][ly])));
                    }
                }
                if(cpoint.x < n-1){
                    int lx = cpoint.x + 1;
                    int ly = cpoint.y;
                    if(vis[lx][ly] == 0){
                        dist[lx][ly] = Math.min(dist[lx][ly], Math.max(dist[cpoint.x][cpoint.y], Math.abs(cpoint.height - heights[lx][ly])));
                    }
                }
                if(cpoint.y > 0){
                    int lx = cpoint.x;
                    int ly = cpoint.y - 1;
                    if(vis[lx][ly] == 0){
                        dist[lx][ly] = Math.min(dist[lx][ly], Math.max(dist[cpoint.x][cpoint.y], Math.abs(cpoint.height - heights[lx][ly])));
                    }
                }
                if(cpoint.y < m-1){
                    int lx = cpoint.x;
                    int ly = cpoint.y + 1;
                    if(vis[lx][ly] == 0){
                        dist[lx][ly] = Math.min(dist[lx][ly], Math.max(dist[cpoint.x][cpoint.y], Math.abs(cpoint.height - heights[lx][ly])));
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
}