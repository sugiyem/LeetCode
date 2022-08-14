class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int minRange = pow(10, n - 1), maxRange = pow(10, n) - 1;
        
        for (int i = maxRange; i >= minRange; i--) {
            long long curr = toPalindrome(i);
            for (long long j = ceil(sqrt(curr)); j <= maxRange; j++) {
                if (!(curr % j)) return curr % 1337;
            }
        }
        
        return -1;
    }
private:
    long long toPalindrome(int n) {
        string temp1 = to_string(n), temp2 = to_string(n);
        reverse(temp2.begin(), temp2.end());
        return stol(temp1 + temp2);
    }
};