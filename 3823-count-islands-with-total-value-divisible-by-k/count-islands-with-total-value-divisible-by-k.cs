public class Solution {
    public int CountIslands(int[][] grid, int k) {
        int cnt  = 0;
        for (int i=0; i<grid.Length; i++) {
            for (int j=0; j<grid[0].Length; j++) {
                if (grid[i][j] > 0) {
                    var sum = SumIsland(grid, i, j);
                    if (sum%k == 0) cnt++;
                }
            }
        }

        return cnt;
    }

    int SumIsland(int[][] grid, int i, int j) {
        int sum = grid[i][j];
        grid[i][j] = 0;

        if (i > 0 && grid[i-1][j] > 0) {
            sum += SumIsland(grid, i-1, j);
        }
        if (j > 0 && grid[i][j-1] > 0) {
            sum += SumIsland(grid, i, j-1);
        }
        if (i < grid.Length-1 && grid[i+1][j] > 0) {
            sum += SumIsland(grid, i+1, j);
        }
        if (j < grid[0].Length-1 && grid[i][j+1] > 0) {
            sum += SumIsland(grid, i, j+1);
        }

        return sum;
    }
}