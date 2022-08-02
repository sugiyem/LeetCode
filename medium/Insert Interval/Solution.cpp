class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int index = 0, length = intervals.size();
        
        while(index < length && intervals[index][1] < newInterval[0]) {
            ans.push_back(intervals[index]);
            index++;
        }
        
        while(index < length && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        
        ans.push_back(newInterval);
        
        while(index < length) {
            ans.push_back(intervals[index]);
            index++;
        }
        
        return ans;
    }
};