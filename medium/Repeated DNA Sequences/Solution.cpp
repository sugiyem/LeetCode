class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 10) {
            return ans;
        }
        unordered_map<char, int> mp;
        unordered_map<int, int> um;
        mp['A'] = 0;mp['C'] = 1;mp['G']=2;mp['T'] = 3;
        for (int i = 0; i <= s.size() - 10; ++i) {
            int id = 0;
            for (int j = 0; j < 10; ++j) {
                id <<= 2;
                id |= mp[s[i + j]];
            }
            if (um[id]++ == 1) {
                ans.push_back(s.substr(i, 10));
            }
        }
        return ans;
    }
};