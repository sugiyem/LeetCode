class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n), ans;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (auto e : edges) {
            int v1 = e[0] - 1, v2 = e[1] - 1;
            
            while (parent[v1] != v1) {
                v1 = parent[v1];
            }
            while (parent[v2] != v2) {
                v2 = parent[v2];
            }
            
            if (v1 == v2) {
                ans = e;
            } else {
                parent[v1] = v2;
            }
        }
        return ans;
    }
};