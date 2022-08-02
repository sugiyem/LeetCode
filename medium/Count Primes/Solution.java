class Solution {
    public int countPrimes(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }
        
        boolean[] primeList = new boolean[n];
        int ans = 0;
        
        for (int i = 2; i < n; ++i) {
            if (!primeList[i]) {
                ++ans;
                for (int j = i; j < n; j+=i) {
                    primeList[j] = true;
                }
            }
        }
        
        return ans;
    }
}