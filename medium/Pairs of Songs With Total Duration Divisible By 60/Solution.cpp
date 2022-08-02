class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60, 0);
        int ans = 0;
        for (int u : time) {
            if (u % 60 == 0) {
                ans += freq[0];
            } else {
                ans += freq[60 - (u % 60)];
            }
            ++freq[u % 60];
        }
        return ans;
    }
};