class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = target;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum < 0 || sum & 1) {
            return 0;
        }
        sum >>= 1;
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = vector<int>(sum + 1, 0);
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];;
                }
            }
        }
        // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]
        return dp[n][sum];
    }
};