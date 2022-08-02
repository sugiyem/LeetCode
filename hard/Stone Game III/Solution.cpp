class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int curr = 0;
            for (int j = 0; j < 3 && i + j < n; ++j) {
                curr += stoneValue[i + j];
                dp[i] = max(dp[i], curr - dp[i + j + 1]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};