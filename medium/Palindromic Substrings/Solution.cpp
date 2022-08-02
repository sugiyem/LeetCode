class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), ans = 0;
        vector<vector<bool>>dp(len, vector<bool>(len, false));
        
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j - i < 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};