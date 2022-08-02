class Solution {
public:
    unordered_map<int, int> memo;
    
    int find(int x) {
        if (memo[x] || x == 1) {
            return memo[x];
        }
        
        if (x % 2) {
            memo[x] = 1 + find(3 * x + 1);
        } else {
            memo[x] = 1 + find(x >> 1);
        }
        
        return memo[x];
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powers;
        for (int i = lo; i <= hi; ++i) {
            powers.push_back({find(i), i});
        }
        sort(powers.begin(), powers.end());
        return powers[k - 1].second;
    }
};