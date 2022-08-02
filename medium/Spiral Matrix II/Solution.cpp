class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n));
        vector<vector<int>>direction{{0,1},{1,0},{0,-1},{-1,0}};
        int i = n, j = n, x = 0, y = -1, pos = 0, curr = 1;
        while(i && j) {
            if (pos % 2 == 0) {
                for (int k = 0; k < i; ++k) {
                    x = x + direction[pos % 4][0];
                    y = y + direction[pos % 4][1];
                    ans[x][y] = curr++;
                }
                --j;
                ++pos;
            } else {
                for (int k = 0; k < j; ++k) {
                    x = x + direction[pos % 4][0];
                    y = y + direction[pos % 4][1];
                    ans[x][y] = curr++;
                }
                --i;
                ++pos;
            }
        }
        return ans;
    }
};