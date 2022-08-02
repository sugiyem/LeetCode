class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int start = 0, currMax = 0, ans = 0;
        
        for (int i  = 0; i < s.length(); i++) {
            currMax = max(currMax, ++freq[s[i] - 'A']);
            
            while(i - start - currMax + 1 > k) {
                freq[s[start] - 'A']--;
                start++;
                currMax = 0;
                for (int j = 0; j < 26; j++) {
                    currMax = max(currMax, freq[j]);
                }
            }
            
            ans = max(ans, i - start + 1);
        }
        
        return ans;
    }
};