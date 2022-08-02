class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, vis(n, 0);
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, vis, i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int start) {
        if (vis[start] != 0) {
            return vis[start] == 1;
        }
        
        vis[start] = 2;
        for (int next : graph[start]) {
            if (!dfs(graph, vis, next)) {
                return false;
            }
        }
        
        vis[start] = 1;
        return true;
    }
};