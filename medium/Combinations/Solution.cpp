class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, k, 1, n);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, int num, int start, int end) {
        if (num == 0) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = start; i <= end; i++) {
            curr.push_back(i);
            backtrack(ans, curr, num - 1, i + 1, end);
            curr.pop_back();
        }
    }
};