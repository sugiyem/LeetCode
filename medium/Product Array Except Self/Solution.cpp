class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size(), product = 1;
        vector<int> ans(length, 1);
        
        for (int i = 1; i < length; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        for (int i = length - 1; i >= 0; i--) {
            ans[i] *= product;
            product *= nums[i];
        }
        
        return ans;
    }
};