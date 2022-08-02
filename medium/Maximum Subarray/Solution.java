class Solution {
    public int maxSubArray(int[] nums) {
        int currMax = nums[0];
        int currLeftMax = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            currLeftMax = Math.max(currLeftMax + nums[i], nums[i]);
            currMax = Math.max(currMax, currLeftMax);
        }
        return currMax;
    }
}