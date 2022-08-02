class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (i == digits.size() - 1) {
                ans.push_back((digits[i] + 1) % 10);
                carry = (digits[i] + 1) / 10;
            }
            else {
                ans.push_back((digits[i] + carry) % 10);
                carry = (digits[i] + carry) / 10;
            }
        }
        if (carry) {
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};