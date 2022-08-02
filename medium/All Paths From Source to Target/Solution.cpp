class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(graph, ans, temp, 0);
        return ans;
    }
    
    void backtrack(vector<vector<int>>& graph, vector<vector<int>>& ans,
                   vector<int>& temp, int curr) {
        temp.push_back(curr);
        if (curr == graph.size() - 1) {
            ans.push_back(temp);
        } else {
            for (int i : graph[curr]) {
                backtrack(graph, ans, temp, i);
            }
        }
        temp.pop_back();
    }
};