class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> outDegree(numCourses), topoSort;
        vector<vector<int>> graph(numCourses);
        
        for (auto e : prerequisites) {
            outDegree[e[0]]++;
            graph[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (outDegree[i] == 0) {
                topoSort.push_back(i);
            }
        }
        
        for (int i = 0; i < topoSort.size(); i++) {
            for (int j : graph[topoSort[i]]) {
                if(--outDegree[j] == 0) {
                    topoSort.push_back(j);
                }
            }
        }
        
        return topoSort.size() == numCourses;
    }
};