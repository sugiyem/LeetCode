class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, nums, curr, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int start) {
        ans.push_back(curr);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                curr.push_back(nums[i]);
                backtrack(ans, nums, curr, i + 1);
                curr.pop_back();
            }
        }
    }
};