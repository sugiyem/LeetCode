class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k = -1, t;
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k =  i;
                break;
            }
        }
        
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for (int i = n - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                t = i;
                break;
            }
        }
        
        swap(nums[k], nums[t]);
        reverse(nums.begin() + k + 1, nums.end());
        
        
    }
};