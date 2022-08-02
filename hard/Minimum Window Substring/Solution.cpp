class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        int cnt = 0, start = 0, ans_start = 0, ans_len = 1e5 + 5, len = t.length();
        
        for (int i = 0; i < len; i++) {
            freq[t[i]]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]]-- > 0) {
                cnt++;
            }
            
            if (cnt == len) {
                while(start < i && freq[s[start]] < 0) {
                    freq[s[start++]]++;
                }
                
                if (ans_len > i - start + 1) {
                    ans_len = i - start + 1;
                    ans_start = start;
                }
                
                freq[s[start++]]++;
                cnt--;
            }
        }
        
        return ans_len == 1e5 + 5 ? "" : s.substr(ans_start, ans_len);
    }
};