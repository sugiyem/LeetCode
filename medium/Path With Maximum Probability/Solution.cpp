class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        vector<double> curr(n, 0.0);
        vector<bool> vis(n, false);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start));
        curr[start] = 1.0;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if (vis[t.second]) {
                continue;
            }
            vis[t.second] = true;
            if (t.second == end) {
                return curr[end];
            }
            for (auto e : graph[t.second]) {
                if (!vis[e.first] && curr[e.first] < curr[t.second] * e.second) {
                    curr[e.first] = curr[t.second] * e.second;
                    pq.push(make_pair(curr[e.first], e.first));
                }
            }
        }
        return 0;
        
    }
};