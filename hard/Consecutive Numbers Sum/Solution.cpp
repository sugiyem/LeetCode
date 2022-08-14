class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // every odd integer x | n with x (x + 1) / 2 <= n
        // every even integer x with x/2 | n, 2n / x odd, x (x + 1) / 2 <= n
        // O(sqrt(n))
        int x = 1, ans = 0;
        while (x * (x + 1) / 2 <= n) {
            if ((x & 1) && !(n % x)) ans++;
            if (!(x & 1) && !(n % (x >> 1)) && (n / (x >> 1) & 1)) ans++;
            
            x++;
        }
        
        return ans;
    }
};