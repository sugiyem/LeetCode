class Solution {
public:
    int countArrangement(int n) {
        if (n < 4) {
            return n;
        }
        
        countAns(n, 1);
        return ans;
    }
private:
    int ans = 0;
    int vis = 0;
    
    void countAns(int n, int start) {
        if (start > n) {
            ++ans;
            return;
        }
        int bit;
        for (int i = 1; i <= n; ++i) {
            bit = 1 << i;
            if (!(vis & bit) && (i % start == 0 || start % i == 0)) {
                vis ^= bit;
                countAns(n, start + 1);
                vis ^= bit;
            }
        }
        
    }
};