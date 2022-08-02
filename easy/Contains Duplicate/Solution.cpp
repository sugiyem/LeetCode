class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        
        for (int u : nums) {
            // if u is already found before
            if (!unique.insert(u).second) {
                return true;
            }
        }
        
        return false;
    }
};