class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        deque<int> deq({0});
        
        for (int i = 1; i < len; i++) {
            if (i > deq.front() + k) {
                deq.pop_front();
            }
            
            dp[i] = nums[i] + dp[deq.front()];
            
            while(!deq.empty() && dp[i] >= dp[deq.back()]) {
                deq.pop_back();
            }
            
            deq.push_back(i);
        }
        
        return dp[len - 1];
    }
};