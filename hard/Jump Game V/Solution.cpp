class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0, len = arr.size();
        vector<int>dp(len, 0);
        
        for (int i = 0; i < len; i++) {
            ans = max(ans, read(arr, dp, i, d));
        }
        
        return ans;
    }
private:
    int read(vector<int>& arr, vector<int>& dp, int index, int dist) {
        if (dp[index]) return dp[index];
        int len = dp.size();
        dp[index] = 1;
        
        for (int i = index + 1; i <= min(len - 1, index + dist); i++) {
            if (arr[i] >= arr[index]) break;
            dp[index] = max(dp[index], 1 + read(arr, dp, i, dist));
        }
        
        for (int i = index - 1; i >= max(0, index - dist); i--) {
            if (arr[i] >= arr[index]) break;
            dp[index] = max(dp[index], 1 + read(arr, dp, i, dist));
        }
        
        return dp[index];
    }
};