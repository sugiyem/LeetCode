class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int index = 0, len = nums.size();
        
        while(index < len) {
            int left = index + 1;
            int right = len - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] < -nums[index]) {
                    left++;
                } else if (nums[left] + nums[right] > -nums[index]) {
                    right--;
                } else {
                    ans.push_back({nums[index], nums[left], nums[right]});
                    
                    while (left < right - 1 && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    while (right > left + 1 && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
            }
            
            while(index < len - 1&& nums[index] == nums[index + 1]) {
                index++;
            }
            
            index++;
        }
        
        return ans;
    }
};