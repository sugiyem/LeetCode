class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> dp(n + 1, 0), deg(n + 1, 0);
        int ans = 0;
        stack<int> s;
        for (auto u : relations) {
            graph[u[0]].push_back(u[1]);
            ++deg[u[1]];
        }
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 0) {
                s.push(i);
                dp[i] = time[i - 1];
            }
        }
        while(!s.empty()) {
            int curr = s.top();
            s.pop();
            for (int next : graph[curr]) {
                dp[next] = max(dp[next], dp[curr] + time[next - 1]);
                --deg[next];
                if (deg[next] == 0) {
                    s.push(next);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};