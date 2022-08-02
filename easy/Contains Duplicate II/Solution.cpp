class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        
        if (k <= 0) {
            return false;
        }
        
        if (k >= len) {
            k = len - 1;
        }
        
        unordered_map<int, int> freq;
        
        for (int i = 0; i < len; i++) {
            if (i > k) {
                freq[nums[i - k - 1]]--;
            }
            
            if (freq[nums[i]]++) {
                return true;
            }
        }
        
        return false;
    }
};