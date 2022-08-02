class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        boolean[] dp = new boolean[n];
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= Math.min(nums[i], n - 1 -i); ++j) {
                dp[i] = dp[i] || dp[i + j];
            }
        }
        return dp[0];
    }
}