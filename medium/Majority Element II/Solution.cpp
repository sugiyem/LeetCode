class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int target = nums.size() / 3;
        unordered_map<int, int> freq;
        for (int x : nums) {
            ++freq[x];
        }
        for (auto u : freq) {
            if (u.second > target) {
                ans.push_back(u.first);
            }
        }
        return ans;
        
    }
};