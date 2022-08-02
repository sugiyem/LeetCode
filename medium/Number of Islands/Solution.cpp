class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid);
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
    
private:
    vector<vector<int>> dir = {{0, 1},{0,-1},{1,0},{-1,0}};
    
    void dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()
               && grid[newX][newY] == '1' && !vis[newX][newY]) {
                dfs(newX, newY, vis, grid);
            }
        }
    } 
    
};