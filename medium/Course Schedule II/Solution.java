class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        ArrayList<Integer> topoSort = new ArrayList<>();
        int[] outDegree = new int[numCourses];
        
        for (int i = 0; i < numCourses; ++i) {
            graph[i] = new ArrayList<Integer>();
        }
        
        for (int[] edge : prerequisites) {
            ++outDegree[edge[0]];
            graph[edge[1]].add(edge[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (outDegree[i] == 0) {
                topoSort.add(i);
            }
        }
        
        for (int i = 0; i < topoSort.size(); ++i) {
            for (int j : graph[topoSort.get(i)]) {
                if(--outDegree[j] == 0) {
                    topoSort.add(j);
                }
            }
        }
        
        if (topoSort.size() < numCourses) {
            return new int[0];
        }
        
        int[] ans = new int[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            ans[i] = topoSort.get(i);
        }
        return ans;
    }
}