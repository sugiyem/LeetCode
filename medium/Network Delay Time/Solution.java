class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        boolean[] vis = new boolean[n];
        int[] dist = new int[n];
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(graph[i], -1);
        }
        
        for (int i = 0; i < times.length; ++i) {
            graph[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }
        
        Arrays.fill(dist, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> {
            if (x[1] != y[1]) {
                return x[1] < y[1] ? -1 : 1;
            }
            return x[0] - y[0];
        });
        dist[k - 1] = 0;
        pq.add(new int[]{k - 1, 0});
        int ans = 0;
        while(!pq.isEmpty()) {
            int[] curr = pq.remove();
            if (vis[curr[0]]) {
                continue;
            }
            ans = Math.max(ans, curr[1]);
            vis[curr[0]] = true;
            
            for (int i = 0; i < n; ++i) {
                if (graph[curr[0]][i] >= 0) {
                    if (dist[i] > curr[1] + graph[curr[0]][i]) {
                        dist[i] = curr[1] + graph[curr[0]][i];
                        pq.add(new int[]{i, dist[i]});
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return -1;
            }
        }
        
        return ans;
    }
}