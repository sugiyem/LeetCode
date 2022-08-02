class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> v(n);
        vector<int> c(n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                q.push(i);
                v[i] = true;
                c[i] = -1;
                while(!q.empty()) {
                    int p = q.front();
                    q.pop();
                    for (int k : graph[p]) {
                        if (!v[k]) {
                            v[k] = true;
                            c[k] = -c[p];
                            q.push(k);
                        }
                        if (c[k] == c[p]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};