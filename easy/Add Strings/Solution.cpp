class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
        while(i >= 0 || j >= 0 || carry == 1) {
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            ans = to_string((x + y + carry) % 10) + ans;
            carry = (x + y + carry) / 10;
            --i;
            --j;
        }
        return ans;
    }
};