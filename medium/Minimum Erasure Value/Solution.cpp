class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int start = 0, ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (freq[nums[i]]++ == 1) {
                while(freq[nums[i]] > 1) {
                    freq[nums[start]]--;
                    sum -= nums[start];
                    start++;
                }
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};