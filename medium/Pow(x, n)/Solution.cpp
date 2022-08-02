class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else {
            double ans = myPow(x, abs(n / 2));
            ans = n % 2 == 0 ? ans * ans : x * ans * ans;
            return n > 0 ? ans : 1/ans;
        }
    }
};