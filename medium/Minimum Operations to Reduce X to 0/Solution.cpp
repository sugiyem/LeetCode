class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = -x, ans = -1, len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        
        if (sum < 0) {
            return ans;
        }
        
        int start = 0, end = 0, currSum = 0;
        while(end < len) {
            currSum += nums[end++];
            
            while(currSum > sum) {
                currSum -= nums[start++];
            }
            
            if (currSum == sum) {
                ans = max(ans, end - start);
            }
        }
        
        return ans == -1 ? ans : len - ans;
    }
};