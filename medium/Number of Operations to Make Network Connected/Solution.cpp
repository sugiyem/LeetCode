class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        int num = 0;
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        for (auto e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            stack<int> st;
            st.push(i);
            vis[i] = true;
            while(!st.empty()) {
                int k = st.top();
                st.pop();
                for (int v : graph[k]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        st.push(v);
                    }
                }
            }
            ++num;
        }
        return num - 1;
    }
};