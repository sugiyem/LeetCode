class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, ans, 0);
        return ans;
    }
private:    
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> set;
        
        for (int i = index; i < nums.size(); i++) {
            if (set.count(nums[i])) {
                continue;
            }
            
            set.insert(nums[i]);
            swap(nums[index], nums[i]);
            backtrack(nums, ans, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};