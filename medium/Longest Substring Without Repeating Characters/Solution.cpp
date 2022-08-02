class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastLocation;
        int start = -1, ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (lastLocation.count(s[i])) {
                start = max(start, lastLocation[s[i]]);
            }
            
            lastLocation[s[i]] = i;
            ans = max(ans, i - start);
        }
        
        return ans;
    }
};