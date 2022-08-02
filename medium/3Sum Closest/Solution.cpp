class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), ans = nums[0] + nums[1] + nums.back();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int start = i + 1, end = n - 1;
            
            while (start < end) {
                int currAns = nums[i] + nums[start] + nums[end];
                
                if (currAns == target) {
                    return target;
                } else if (currAns > target) {
                    end--;
                    if (abs(target - ans) > currAns - target) ans = currAns;
                } else {
                    start++;
                    if (abs(target - ans) > target - currAns) ans = currAns;
                }
            }
        }
        
        return ans;
    }
};