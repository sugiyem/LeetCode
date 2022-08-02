class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        int[][] dp = new int[rowIndex + 1][rowIndex + 1];
        for (int i = 0; i <= rowIndex; ++i) {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        for (int i = 0; i <= rowIndex; ++i) {
            ans.add(dp[rowIndex][i]);
        }
        return ans;
    }
}