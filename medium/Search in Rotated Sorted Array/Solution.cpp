class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, minIndex = 0, ans = 0;
        
        // find the index of minimum element
        while(start < end) {
            minIndex = start + (end - start) / 2;
            if (nums[minIndex] > nums[end]) {
                start = minIndex + 1;
            } else {
                end = minIndex;
            }
        }
        
        minIndex = start;
        start = 0;
        end = nums.size() - 1;
    
        if (target < nums[minIndex]) {
            return -1;
        } else if (target <= nums[end]) {
            start = minIndex;
        } else {
            end = minIndex - 1;
        }
        
        // regular binary search
        while(start <= end) {
            ans = start + (end - start) / 2;
            if (nums[ans] == target) {
                return ans;
            } else if (nums[ans] < target) {
                start = ans + 1;
            } else {
                end = ans - 1;
            }
        }
        
        return -1;
    }
};