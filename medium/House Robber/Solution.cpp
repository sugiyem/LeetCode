class Solution {
public:
    int rob(vector<int>& nums) {
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