class Solution {
    public boolean increasingTriplet(int[] nums) {
        int len = nums.length;
        int[] small = new int[len];
        int[] big = new int[len];
        
        int min = 0;
        small[0] = -1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] <= nums[min]) {
                min = i;
                small[i] = -1;
            } else {
                small[i] = min;
            }
        }
        
        int max = len - 1;
        big[len - 1] = -1;
        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] >= nums[max]) {
                max = i;
                big[i] = -1;
            } else {
                big[i] = max;
            }
        }
        
        for (int i = 0; i < len; ++i) {
            if (small[i] != -1 && big[i] != -1) {
                return true;
            }
        }
        
        return false;
    }
}