class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n);
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++ans;
                q.push(i);
                vis[i] = true;
                while(!q.empty()) {
                    int c = q.front();
                    q.pop();
                    for (int j = 0; j < n; ++j) {
                        if (j != c && !vis[j] && isConnected[c][j]) {
                            vis[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};