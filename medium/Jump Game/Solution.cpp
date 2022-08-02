class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() -1;
        for (int i = end; i >= 0; --i) {
            if (i + nums[i] >= end) end = i;
        }
  
        if (end == 0) return true; 
        return false;
    }
};