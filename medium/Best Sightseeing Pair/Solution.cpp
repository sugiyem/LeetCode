class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int len = values.size();
        vector<int> dp(len, 0);
        dp[len - 1] = values[len - 1] - (len - 1); // dont really care
        int ans = INT_MIN;
        
        for (int i = len - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], values[i + 1] - i - 1);
            ans = max(ans, values[i] + i + dp[i]);
        }
        
        return ans;
    }
};