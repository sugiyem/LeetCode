class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0), ans;
        queue<int> q;
        for (auto u : edges) {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
            ++deg[u[0]];
            ++deg[u[1]];
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            ans.clear();
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                int k = q.front();
                ans.push_back(k);
                --deg[k];
                q.pop();
                for (int x : adj[k]) {
                    --deg[x];
                    if (deg[x] == 1) {
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};