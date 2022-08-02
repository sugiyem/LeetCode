class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            last[s[i]] = i;
        }
        int start = -1, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, last[s[i]]);
            if (i == end) {
                ans.push_back(end - start);
                start = end;
                ++end;
            }
        }
        return ans;
    }
};