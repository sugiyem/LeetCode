class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, leftMax = 0, rightMax = 0, left = 0, right = height.size() - 1;
        
        while (left <= right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            
            if (leftMax < rightMax) {
                ans += (leftMax - height[left++]);
            } else {
                ans += (rightMax - height[right--]);
            }
        }
        
        return ans;
    }
};