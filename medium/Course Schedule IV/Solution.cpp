class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<unordered_set<int>> prereq(numCourses);
        vector<int> deg(numCourses, 0);
        vector<bool> ans;
        stack<int> s;
        
        for (auto e : prerequisites) {
            ++deg[e[1]];
            graph[e[0]].push_back(e[1]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (deg[i] == 0) {
                s.push(i);
            }
        }
        
        while(!s.empty()) {
            int curr = s.top();
            s.pop();
            for (int next : graph[curr]) {
                prereq[next].insert(curr);
                prereq[next].insert(prereq[curr].begin(), prereq[curr].end());
                if (--deg[next] == 0) {
                    s.push(next);
                }
            }
        }
        
        for (auto query : queries) {
            ans.push_back(prereq[query[1]].find(query[0]) != prereq[query[1]].end());
        }
        
        return ans;
        
        
    }
};