class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstIndex(nums, target, 0);
        
        if (first == -1) {
            return {-1, -1};
        } else {
            return {first, findLastIndex(nums, target, first)};
        }
    }
private:
    int findFirstIndex(vector<int>& nums, int target, int start) {
        int begin = start, end = nums.size() - 1, ans = -1;
        
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid -1;
                ans = mid;
            }
        }
        
        return ans;
    }
    
    int findLastIndex(vector<int>& nums, int target, int start) {
        int begin = start, end = nums.size() - 1, ans = -1;
        
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                begin = mid + 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};