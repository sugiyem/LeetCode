class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<bool> vis(n);
        unordered_map<int, vector<int>> indices;
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        
        vis[0] = true;
        q.push(0);
        
        // Do BFS
        while(!q.empty()) {
            int currLength = q.size();
            for (int i = 0; i < currLength; i++) {
                int currIndex = q.front();
                if (currIndex == n - 1) return ans; // reach already
                q.pop();
                
                indices[arr[currIndex]].push_back(currIndex - 1);
                indices[arr[currIndex]].push_back(currIndex + 1);
                
                for (int j : indices[arr[currIndex]]) {
                    if (j >= 0 && j < n && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                
                indices[arr[currIndex]].clear();
            }
            ans++;
        }
        
        return 0;
    }
};