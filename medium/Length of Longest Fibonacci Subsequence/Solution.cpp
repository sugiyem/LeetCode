class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> id;
        int n = arr.size(), ans = 0;
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            id[arr[i]] = i;
            for (int j = 0; j < i; ++j) {
                int k = id.find(arr[i] - arr[j]) == id.end() ? -1 : id[arr[i] - arr[j]];
                if (arr[i] - arr[j] < arr[j] && k >= 0) {
                    dp[j][i] = 1 + dp[k][j];
                    ans = max(ans, dp[j][i]);
                } else {
                    dp[j][i] = 2;
                }
            }
        }
        return ans;
    }
};