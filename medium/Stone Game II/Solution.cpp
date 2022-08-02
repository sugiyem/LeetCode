class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1);
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + piles[i];
            dp[i] = vector<int>(n + 1, 0);
        }
        dp[n] = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[n][i] = 0;
            dp[n - 1][i] = piles[n - 1];
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n; j > 0; --j) {
                for (int k = 0; k < 2 * j; ++k) {
                    if (i + k >= n) {
                        break;
                    }
                    dp[i][j] = max(dp[i][j], sum[n] - sum[i] - 
                                   dp[i + k + 1][min(n, max(j, k + 1))]);   
                }
            }
        }
        return dp[0][1];
    }
};