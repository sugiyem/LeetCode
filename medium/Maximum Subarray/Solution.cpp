class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], leftMax = nums[0], length = nums.size();
        for (int i = 1; i < length; i++) {
            leftMax = leftMax > 0 ? leftMax + nums[i] : nums[i];
            ans = max(ans, leftMax);
        }
        return ans;
    }
};