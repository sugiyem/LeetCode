class Solution {
    public static final int[][] dir = new int[][]{new int[]{0, 1}, new int[]{0, -1}, 
                                            new int[]{1, 0}, new int[]{-1, 0}};
    
    public void dfs(int x, int y, boolean[][] vis, char[][] grid) {
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            
            if (newX >= 0 && newX < grid.length && newY >= 0 && newY < grid[0].length
               && grid[newX][newY] == '1' && !vis[newX][newY]) {
                dfs(newX, newY, vis, grid);
            }
        }
    } 
    
    public int numIslands(char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        boolean[][] vis = new boolean[row][col];
        int ans = 0;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid);
                    ++ans;
                }
            }
        }
        return ans;
    }
}