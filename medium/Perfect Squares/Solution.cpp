class Solution {
public:
    int numSquares(int n) {
        int root = sqrt(n);
        if (root * root == n) {
            return 1;
        }
        int curr = n, count = 0;
        bool cek = true;
        for (int i = 3; i <= n; i += 4) {
            count = 0;
            while (curr % i == 0) {
                ++count;
                curr /= i;
            }
            
            if (count & 1) {
                cek = false;
                break;
            }
        }
        if (cek) {
            return 2;
        }
        
        while (n % 4 == 0) {
            n >>= 2;
        }
        if (n % 8 != 7) {
            return 3;
        }
        
        return 4;
    }
};