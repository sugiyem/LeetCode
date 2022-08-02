lass Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(ans, curr, s, 0);
        return ans;
    }
private:
    bool checkpalindrome(string s) {
        int n = s.length();
        if (n == 0 || n == 1) {
            return true;
        }
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == s[n - 1 - i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    void backtrack(vector<vector<string>>& ans, vector<string>& curr, string s, int start) {
        if (start >= s.length()) {
            ans.push_back(curr);
            return;
        }
        for (int j = 1; j <= s.length() - start; ++j) {
            if (checkpalindrome(s.substr(start, j))) {
                curr.push_back(s.substr(start, j));
                backtrack(ans, curr, s, start + j);
                curr.pop_back();
            }
        }
    }
};