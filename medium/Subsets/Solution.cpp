class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int start) {
        if (start >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[start]);
        backtrack(ans, nums, curr, start + 1);
        curr.pop_back();
        backtrack(ans, nums, curr, start + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, nums, curr, 0);
        return ans;
    }
};