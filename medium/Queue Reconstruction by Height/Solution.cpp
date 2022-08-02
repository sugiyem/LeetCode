class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](vector<int>&a, vector<int>&b) {
            return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
        };
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); ++i) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};