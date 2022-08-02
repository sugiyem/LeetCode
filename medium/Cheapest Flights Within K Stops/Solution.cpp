class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 1e6 + 5);
        dp[src] = 0;
        
        for (int i = 0; i <= k; ++i) {
            vector<int> copy(dp);
            for (auto v : flights) {
                copy[v[1]] = min(copy[v[1]], dp[v[0]] + v[2]);
            }
            dp = copy;
        }
        
        return dp[dst] == 1e6 + 5 ? -1 : dp[dst];
    }
};