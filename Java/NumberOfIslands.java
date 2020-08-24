/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Problem: https://leetcode.com/problems/number-of-islands/submissions/
 * 
 * Submission link: https://leetcode.com/submissions/detail/385691397/
 * 
 * Runtime: 1 ms, faster than 99.94% of Java online submissions
 * 
 * Memory Usage: 42.3 MB, less than 52.50% of Java online submissions
 * 
 * @author Mirzafazulur Rahamanbaig
 *
 */
class NumberOfIslands {

	boolean[][] visited;
	int r, c;
	int islands;

	/**
	 * 
	 * @param grid
	 * @return
	 */
	public int numIslands(char[][] grid) {

		if (grid == null || grid.length == 0) {

			return 0;
		}

		r = grid.length;
		c = grid[0].length;
		islands = 0;
		visited = new boolean[r][c];

		for (int i = 0; i < r; i++) {

			for (int j = 0; j < c; j++) {

				if (grid[i][j] == '1' && !visited[i][j]) {

					_numIslands(grid, i, j);
					islands++;
				}
			}
		}

		return islands;
	}

	/**
	 * 
	 * @param grid
	 * @param m
	 * @param n
	 */
	private void _numIslands(char[][] grid, int m, int n) {

		if (m < 0 || m >= r || n < 0 || n >= c || visited[m][n] || grid[m][n] == '0') {

			return;
		}

		visited[m][n] = true;

		_numIslands(grid, m + 1, n);
		_numIslands(grid, m, n + 1);
		_numIslands(grid, m - 1, n);
		_numIslands(grid, m, n - 1);
	}
}
