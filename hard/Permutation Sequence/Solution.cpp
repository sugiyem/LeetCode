class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n + 1, 1);
        string res, ans;
        k--;
        
        for (int i = 1; i <= n; i++) {
            fact[i] = i * fact[i - 1];
            res.push_back('0' + i);
        }
        
        while(n > 1 && k > 0) {
            int curr = k / fact[n - 1];
            ans.push_back(res[curr]);
            res.erase(curr, 1);
            k -= curr * fact[n - 1];
            n--;
        }
        
        ans += res;
        return ans;
        
    }
};