class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
        
        return topoSort.size() == numCourses;
        
    }
}