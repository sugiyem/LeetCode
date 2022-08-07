class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int>sum(n + 1, 0);
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + stones[i];
        }
        
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i <= n - j; i++) {
                dp[i][j] = max(sum[i + j] - sum[i] - stones[i] - dp[i + 1][j - 1],
                    sum[i + j] - sum[i] - stones[i + j - 1] - dp[i][j - 1]);
            }
        }
        
        return dp[0][n];
    }
};