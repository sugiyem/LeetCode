class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> ans;
        
        for (string str : strs) {
            groups[sort(str)].push_back(str);
        }
        
        for (auto group : groups) {
            ans.push_back(group.second);
        }
        
        return ans;
    }
private:
    string sort(string str) {
        vector<int>count(26);
        string res = "";
        
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            res += string(count[i], i + 'a');
        }
        
        return res;
    }
};