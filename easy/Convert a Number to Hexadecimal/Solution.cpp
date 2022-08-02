class Solution {
public:
    string str = "0123456789abcdef";
    
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        
        string ans = "";
        while(num && ans.length() < 8) {
            ans = str[num & 15] + ans;
            num >>= 4;
        }
        
        return ans;
        
    }
};