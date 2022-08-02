class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modifyCount = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (modifyCount++) {
                    return false;
                }
                
                if (i - 1 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1];
                } else {
                    nums[i - 1] = nums[i];
                }
            }
        }
        
        return true;
    }
};