class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        
        vector<int> numsLeft(nums.begin(), nums.end() - 1);
        vector<int> numsRight(nums.begin() + 1, nums.end());
        return max(linearRob(numsLeft), linearRob(numsRight));
    }
private:
    int linearRob(vector<int>& nums) {
        int robbed = 0;
        int notRobbed = 0;
        
        for (int num : nums) {
            int temp = notRobbed;
            notRobbed = max(notRobbed, robbed);
            robbed = num + temp;
        }
        
        return max(robbed, notRobbed);
    }
};