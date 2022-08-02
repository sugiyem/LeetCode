class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int start = 0, end = 0, ans = 0, prod = 1;
        while (end < nums.size()) {
            prod *= nums[end++];
            while (prod >= k) {
                prod /= nums[start++];
            }
            ans += (end - start);
        }
        return ans;
    }
};