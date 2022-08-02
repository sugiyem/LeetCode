class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size(), pos = 0, x = 0, y = -1;
        while(m > 0 && n > 0) {
            if (pos % 2 == 0) {
                for (int i = 0; i < n; ++i) {
                    x = x + direction[pos % 4][0];
                    y = y + direction[pos % 4][1];
                    ans.push_back(matrix[x][y]);
                }
                --m;
                ++pos;
            } else {
                for (int i = 0; i < m; ++i) {
                    x = x + direction[pos % 4][0];
                    y = y + direction[pos % 4][1];
                    ans.push_back(matrix[x][y]);
                }
                --n;
                ++pos;
            }
        }
        return ans;
        
    }
};