class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n), ans(n);
        vector<int> in(n, 0);
        queue<int> q;
        vector<set<int>> s(n);
        for (auto u : edges) {
            g[u[0]].push_back(u[1]);
            ++in[u[1]];
        }
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                s[u].insert(v);
                for (int x : s[v]) {
                    s[u].insert(x);
                }
                --in[u];
                if (in[u] == 0) {
                    q.push(u);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int x : s[i]) {
                ans[i].push_back(x);
            }
        }
        return ans;
    }
};