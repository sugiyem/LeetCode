class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> reachableFromPacific(m, vector<bool>(n, false));
        vector<vector<bool>> reachableFromAtlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            dfs(heights, reachableFromPacific, i, 0);
            dfs(heights, reachableFromAtlantic, i, n - 1);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(heights, reachableFromPacific, 0, i);
            dfs(heights, reachableFromAtlantic, m - 1, i);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (reachableFromPacific[i][j] && reachableFromAtlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int x, int y) {
        if (reachable[x][y]) {
            return;
        }
        
        int m = heights.size(), n = heights[0].size();
        reachable[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !reachable[newX][newY]
               && heights[newX][newY] >= heights[x][y]) {
                dfs(heights, reachable, newX, newY);
            }
        }
    }
};