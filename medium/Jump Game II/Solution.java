class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = 10005;
            for (int j = 1; j <= Math.min(nums[i], n - 1 - i); ++j) {
                dp[i] = Math.min(dp[i], dp[i + j] + 1);
            }
        }
        return dp[0];
    }
}