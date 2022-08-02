class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j] + dp[i + 1][j];
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j - 1]);
                }
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j + 1]);
                }
            }
        }
        int ans = dp[0][0];
        for (int i = 1; i < n; ++i) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};