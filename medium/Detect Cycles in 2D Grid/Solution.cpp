class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0)), dir = {{0,1},{0,-1},{1,0},{-1,0}};
        stack<vector<int>> s;
        int newX, newY;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j]) {
                    continue;
                }
                s.push({-1,-1,i,j});
                while(!s.empty()) {
                    auto u = s.top();
                    s.pop();
                    vis[u[2]][u[3]] = 1;
                    for (int k = 0; k < 4; ++k) {
                        newX = u[2] + dir[k][0], newY = u[3] + dir[k][1];
                        if (!(newX < 0 || newX >= m || newY < 0 || newY >= n)) {
                            if (!(newX == u[0] && newY == u[1])) {
                                if (grid[newX][newY] == grid[i][j]) {
                                    if (vis[newX][newY]) {
                                        return true;
                                    } else {
                                        s.push({u[2],u[3],newX,newY});
                                    }
                                }
                            } 
                        }
                    }
                }
                
            }
        }
        return false;
    }
};