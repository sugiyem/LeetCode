class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, end = nums.size() - 1;
        
        while(end) {
            int pt1 = 0, pt2 = end - 1;
            while(pt1 < pt2) {
                if (nums[pt1] + nums[pt2] > nums[end]) {
                    ans += (pt2 - pt1);
                    pt2--;
                } else pt1++;
            }
            end--;
        }
        
        return ans;
    }
};