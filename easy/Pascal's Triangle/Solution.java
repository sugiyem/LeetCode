class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        int[][] dp = new int[numRows][numRows];
        for (int i = 0; i < numRows; ++i) {
            dp[i][0] = 1;
            dp[i][i] = 1;
            ans.add(new ArrayList<>());
        }
        
        for (int i = 0; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            for (int j = 0; j <= i; ++j) {
                ans.get(i).add(dp[i][j]);
            }
        }
        
        return ans;
        
        
    }
}