class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
            dp[i] = vector<int>(n, 0);
            dp[0][i] = nums[i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = max(nums[j] + sum[j] - sum[j - i] - dp[i - 1][j - 1],
                              nums[j - i] + sum[j + 1] - sum[j - i + 1] - dp[i - 1][j]);
            }
        }
        return dp[n - 1][n - 1] * 2 - sum[n] >= 0;
    }
};