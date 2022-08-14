class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long l = lcm(a, b);
        long numPerGroup = (l/a) + (l/b) - 1, numOfGroups = (n - 1) / numPerGroup;
        long accumulated = (l % MOD) * numOfGroups % MOD;
        long extraNeeded = n - numPerGroup * numOfGroups, extraAdded = 0;
        int aIndex = 1, bIndex = 1;
        
        while(extraNeeded--) {
            if (a * aIndex <= b * bIndex) extraAdded = (a * aIndex++) % MOD;
            else extraAdded = (b * bIndex++) % MOD;
        }
        
        return (accumulated + extraAdded) % MOD;
    }
private:
    int MOD = 1e9 + 7;
};