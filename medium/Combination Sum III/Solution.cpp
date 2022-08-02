class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, k, n, 1);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, int k, int n, int start) {
        if (curr.size() == k && n == 0) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            if (i > n) break;
            curr.push_back(i);
            backtrack(ans, curr, k, n - i, i + 1);
            curr.pop_back();
        }
    }
};