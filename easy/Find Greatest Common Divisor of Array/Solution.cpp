class Solution {
public:
    int findGCD(vector<int>& nums) {
        int currMin = nums[0], currMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currMin = min(currMin, nums[i]);
            currMax = max(currMax, nums[i]);
        }
        return __gcd(currMin, currMax);
    }
};