class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftMax = 1, rightMax = 1, ans = nums[0], len = nums.size();
        
        for (int i = 0; i < len; i++) {
            leftMax = (leftMax == 0 ? 1 : leftMax) * nums[i];
            rightMax = (rightMax == 0 ? 1 : rightMax) * nums[len - i - 1];
            ans = max(ans, max(leftMax, rightMax));
        }
        
        return ans;
    }
};