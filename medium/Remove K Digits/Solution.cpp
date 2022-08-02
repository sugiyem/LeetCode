class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        
        if (len <= k) {
            return "0";
        }
        
        string ans = "";
        
        for (int i = 0; i < len; i++) {
            while(ans.size() && ans.back() > num[i] && k) {
                ans.pop_back();
                k--;
            }
            
            if (ans.size() || num[i] != '0') {
                ans.push_back(num[i]);
            }
        }
        
        while(ans.size() && k) {
            ans.pop_back();
            k--;
        }
        
        if (ans == "") {
            return "0";
        }
        
        return ans;
    }
};