class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // if target - nums[i] is already found before, break
            if (map.find(target - nums[i]) != map.end()) {
                ans = {i, map[target - nums[i]]};
                break;
            } 
            
            map[nums[i]] = i;
        }
        return ans;
    }
};