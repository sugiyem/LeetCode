class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        if (s[n - 1] != '0') return false;
        
        int cnt = 0;
        vector<bool>dp(n);
        dp[0] = true;
        
        for (int i = 1; i < n; i++) {
            if (i > maxJump) cnt -= dp[i - maxJump - 1];
            if (i >= minJump) cnt += dp[i - minJump];
            if (cnt > 0 && s[i] == '0') dp[i] = true;
        }
        
        return dp[n - 1];
    }
};