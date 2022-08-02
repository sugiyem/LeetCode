class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int len = words.size(), idx = 0;
        unordered_map<string, int> freq;
        vector<set<string>> t(len + 1);
        vector<string> ans;
        for (string s : words) {
            ++freq[s];
        }
        for (auto u : freq) {
            t[u.second].insert(u.first);
        }
        for (int i = len; i >= 0; --i) {
            for (string s : t[i]) {
                ans.push_back(s);
                ++idx;
                if (idx == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};