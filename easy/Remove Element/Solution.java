class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length == 0) {
            return 0;
        }
        
        int k = 0;
        while(k < nums.length && nums[k] != val) {
            ++k;
        }
        
        int pt1 = k;
        int pt2 = k;
        while(pt2 < nums.length) {
            if (nums[pt1] != val) {
                ++pt1;
            } else {
                if (nums[pt2] == val) {
                    ++pt2;
                } else {
                    nums[pt1] = nums[pt2];
                    nums[pt2] = val;
                    ++pt1;
                    ++pt2;
                }
            }
        }
        
        return pt1;
    }
}