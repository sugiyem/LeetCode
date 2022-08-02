class Solution {
public:
    int MOD = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n + 1);
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else if ('1' <= s[i] && s[i] <= '9') {
                dp[i] = dp[i + 1];
                if (i < n - 1 && s[i] == '1') {
                    dp[i] = s[i + 1] == '*' ? (dp[i] + 9 * dp[i + 2]) % MOD 
                        : (dp[i] + dp[i + 2]) % MOD; 
                } else if (i < n - 1 && s[i] == '2') {
                    dp[i] = s[i + 1] == '*' ? (dp[i] + 6 * dp[i + 2]) % MOD
                        : '0' <= s[i + 1] && s[i + 1] <= '6' ? (dp[i] + dp[i + 2]) % MOD
                        : dp[i];
                }
            } else {
                dp[i] = (9 * dp[i + 1]) % MOD;
                if (i < n - 1) {
                    if (s[i + 1] == '*') {
                        dp[i] = (dp[i] + 15 * dp[i + 2]) % MOD;
                    } else if ('0' <= s[i + 1] && s[i + 1] <= '6') {
                        dp[i] = (dp[i] + 2 * dp[i + 2]) % MOD;
                    } else {
                        dp[i] = (dp[i] + dp[i + 2]) % MOD;
                    }
                }
            }
        }
        
        return dp[0] % MOD;
    }
};