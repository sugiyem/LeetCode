class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> boundary;
        int ans = 0;
        
        for (int i : nums) {
            if (boundary[i]) {
                continue;
            }
            
            int left = boundary[i - 1], right = boundary[i + 1];
            
            if (left && right) {
                boundary[i - left] = 1 + left + right;
                boundary[i + right] = 1 + left + right;
                boundary[i] = 1;
                ans = max(ans, 1 + left + right);
            } else if (left) {
                boundary[i - left] = 1 + left;
                boundary[i] = 1 + left;
                ans = max(ans, 1 + left);
            } else if (right) {
                boundary[i + right] = 1 + right;
                boundary[i] = 1 + right;
                ans = max(ans, 1 + right);
            } else {
                boundary[i] = 1;
                ans = max(ans, 1);
            }
        }
        
        return ans;
    }
};