class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), ans = 0, curr = 0, diff = 0, id = 0;
        while(id < n) {
            diff += (gas[id] - cost[id]);
            if (curr + gas[id] >= cost[id]) {
                curr += (gas[id] - cost[id]);
                ++id;
            } else {
                curr = 0;
                ans = ++id;
            }
        }
        return diff < 0 ? -1 : ans;
    }
};