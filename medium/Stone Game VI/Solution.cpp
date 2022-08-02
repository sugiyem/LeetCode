class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size(), alice = 0, bob = 0;
        vector<int>sum(n, 0);
        for (int i = 0; i < n; ++i) {
            bob += bobValues[i];
            sum[i] = aliceValues[i] + bobValues[i];
        }
        sort(sum.begin(), sum.end());
        
        for (int i = n - 1; i >= 0; i-=2) {
            alice += sum[i];
        }
        return alice > bob ? 1 : alice < bob ? -1 : 0;
    }
};