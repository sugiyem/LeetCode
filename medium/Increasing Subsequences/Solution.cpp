class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(ans, nums, curr, 0);
        for (auto v : ans) {
            res.push_back(v);
        }
        return res;
    }
    
private:
    void backtrack(set<vector<int>>& ans, vector<int>& nums, 
                   vector<int>& curr, int start) {
        if (curr.size() > 1) {
            ans.insert(curr);
        }
        for (int i = start; i < nums.size(); ++i) {
            if (curr.size() == 0 || curr[curr.size() - 1] <= nums[i]) {
                curr.push_back(nums[i]);
                backtrack(ans, nums, curr, i + 1);
                curr.pop_back();
            }
        }
    }
};