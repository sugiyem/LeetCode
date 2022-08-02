class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        unordered_map<char, int> freq;
        vector<string> ls(len + 1, "");
        string ans = "";
        for (char c : s) {
            ++freq[c];
        }
        for (auto v : freq) {
            for (int i = 0; i < v.second; ++i) {
                ls[v.second] += v.first;
            }
        }
        for (int i = len; i > 0; --i) {
            ans += ls[i];
        }
        return ans;
    }
};