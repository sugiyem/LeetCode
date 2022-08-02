class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            ++freq[x];
        }
        int target = nums.size() / 2;
        for (auto u : freq) {
            if (u.second > target) {
                return u.first;
            }
        }
        return -1;
    }
};