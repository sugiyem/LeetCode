class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0, zero = 0;
        while (end < nums.size()) {
            if(nums[end++] == 0) {
                ++zero;
            }
            while (zero > k) {
                if (nums[start++] == 0) {
                    --zero;
                }
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};