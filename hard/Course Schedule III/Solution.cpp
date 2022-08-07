class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
             [](vector<int>& v1, vector<int>& v2) {
                 return v1[1] < v2[1];
             });
        priority_queue<int> pq;
        int cnt = 0;
        
        for (vector<int>& curr : courses) {
            cnt += curr[0];
            pq.push(curr[0]);
            
            if (cnt > curr[1]) {
                cnt -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};