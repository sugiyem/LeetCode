class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.size();
        int dist[][] = new int[len][len];
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        
        dist[0][0] = triangle.get(0).get(0);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dist[i][j] = dist[i - 1][j] + triangle.get(i).get(j);
                } else if (j == i) {
                    dist[i][j] = dist[i - 1][j - 1] + triangle.get(i).get(j);
                } else {
                    dist[i][j] = Math.min(dist[i - 1][j - 1], dist[i - 1][j])
                        + triangle.get(i).get(j);
                }
            }
        }
        int ans = dist[len - 1][0];
        for (int i = 1; i < len; ++i) {
            ans = Math.min(ans, dist[len - 1][i]);
        }
        return ans;
    }
}