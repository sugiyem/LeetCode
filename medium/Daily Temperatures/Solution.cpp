class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int curr;
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                curr = s.top();
                s.pop();
                ans[curr] = i - curr;
            }
            s.push(i);
        }
        return ans;
    }
};