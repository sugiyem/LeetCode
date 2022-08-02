class Solution {
public:
    int sum[505];
    int dp[505][505];
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + stoneValue[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; i + j < n; ++j) {
                for (int k = 0; k < j; ++k) {
                    int x = sum[i + k + 1] - sum[i], y = sum[i + j + 1] - sum[i + k + 1];
                    if (x > y) {
                        dp[i][j] = max(dp[i][j], y + dp[i + k + 1][j - k - 1]);
                    } else if (y > x) {
                        dp[i][j] = max(dp[i][j], x + dp[i][k]);
                    } else {
                        dp[i][j] = max(dp[i][j], x + dp[i][k]);
                        dp[i][j] = max(dp[i][j], x + dp[i + k + 1][j - k - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};