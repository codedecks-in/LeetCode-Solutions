# Time Complexity = O(rows*columns)
# Space Complexity = O(rows*columns)

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        count = 0
        rotten = []
        for i in range(n):
            for j in range(m):
                if grid[i][j]==2:
                    rotten.append((i,j))
                    count+=1
                elif grid[i][j] == 1:
                    count+=1
            
        
        if count == 0:
            return 0
        
        cycles = 0
        
        while rotten:
            count-=len(rotten)
            newRotten = []
            for i,j in rotten:
                self.destroy(grid,i+1,j,n,m,newRotten)
                self.destroy(grid,i-1,j,n,m,newRotten)
                self.destroy(grid,i,j+1,n,m,newRotten)
                self.destroy(grid,i,j-1,n,m,newRotten)
            rotten = newRotten
            cycles+=1
        
        if count>0:
            return -1
        else:
            return cycles-1
    
    def destroy(self, grid, i, j, n, m, rotten):
        if 0<=i<n and 0<=j<m:
            if grid[i][j] == 1:
                rotten.append((i,j))
                grid[i][j]=2
            
            
