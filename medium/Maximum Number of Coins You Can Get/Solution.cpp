class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3, sum = 0;
        sort(piles.begin(), piles.end());
        for (int i = n; i < 3 * n; i += 2) {
            sum += piles[i];
        }
        return sum;
    }
};