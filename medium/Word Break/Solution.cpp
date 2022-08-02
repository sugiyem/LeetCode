class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len + 1);
        unordered_set<string> wordSet;
        dp[0] = true;
        
        for (string word : wordDict) {
            wordSet.insert(word);
        }
        
        for (int i = 1; i <= len; i++) {
            int j = i - 1;
            while(!dp[i] && j >= 0) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                }
                j--;
            }
        }
        
        return dp[len];
    }
};