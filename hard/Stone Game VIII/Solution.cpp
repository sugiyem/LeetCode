class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n), dp(n - 1);
        prefix[0] = stones[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = stones[i] + prefix[i - 1];
        }
        
        dp[n - 2] = prefix[n - 1];
        
        for (int i = n - 2; i; i--) {
            dp[i - 1] = max(dp[i], prefix[i] - dp[i]);
        }
        
        return dp[0];
    }
};