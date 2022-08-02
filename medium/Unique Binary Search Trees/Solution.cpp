class Solution {
public:
    int numTrees(int n) {
        // Catalan number
        return combination(2 * n, n)/(n + 1);
    }
private:
    long combination(int n, int k) {
        long ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= (n - i);
            ans /= (i + 1);
        }
        return ans;
    }
};