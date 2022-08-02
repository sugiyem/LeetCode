class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool temp = false;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                temp = false;
            } else {
                if (!temp) {
                    ans = 1;
                    temp = true;
                } else {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};