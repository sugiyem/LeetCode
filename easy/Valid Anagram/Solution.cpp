class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int length = s.length();
        vector<int>freq(26);
        
        for (int i = 0; i < length; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for (int k : freq) {
            if (k) {
                return false;
            }
        }
        
        return true;
    }
};