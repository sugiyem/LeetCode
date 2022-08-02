class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr;
        backtrack(ans, curr, s, 0, 0);
        return ans;
    }
private:
    void backtrack(vector<string>& ans, string curr, string s, int pos, int num) {
        if (s.length() == pos && num == 4) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = pos; i < min((int)s.length(), pos + 3); i++) {
            string currElement = s.substr(pos, i - pos + 1);
            int currValue = stoi(currElement);
            
            if (i > pos && currElement[0] == '0') continue;
            if (currValue >= 0 && currValue <= 255) {
                curr.append(currElement);
                if (++num < 4) curr.push_back('.');
                backtrack(ans, curr, s, i + 1, num);
                if (num-- < 4) curr.pop_back();
                
                for (int j = 0; j <= i - pos; j++) {
                    curr.pop_back();
                }
            }
        }
    }
};