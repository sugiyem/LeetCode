class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), curr = 0;
        vector<bool> vis(n, false);
        queue<int> bfs;
        bfs.push(0);
        vis[0] = true;
        while(!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            ++curr;
            for (int u : rooms[v]) {
                if (!vis[u]) {
                    vis[u] = true;
                    bfs.push(u);
                }
            }
        }
        return curr == n;
    }
};