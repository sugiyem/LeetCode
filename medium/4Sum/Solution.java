class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        int pt1 = 0;
        
        while(pt1 < len) {
            int pt2 = pt1 + 1;
            
            while(pt2 < len) {
                int left = pt2 + 1;
                int right = len - 1;
                
                while(left < right) {
                    if (nums[pt1] + nums[pt2] + nums[left] + nums[right] < target) {
                        ++left;
                    } else if (nums[pt1] + nums[pt2] + nums[left] + nums[right] > target) {
                        --right;
                    } else {
                        ans.add(List.of(nums[pt1], nums[pt2], nums[left], nums[right]));
                        
                        while(left + 1 < right && nums[left] == nums[left + 1]) {
                            ++left;
                        }
                        
                        while(right - 1 > left && nums[right] == nums[right - 1]) {
                            --right;
                        }
                        
                        ++left;
                        --right;
                    }
                }
                
                while(pt2 + 1 < len && nums[pt2] == nums[pt2 + 1]) {
                    ++pt2;
                }
                
                ++pt2;
            }
            
            while(pt1 + 1 < len && nums[pt1] == nums[pt1 + 1]) {
                ++pt1;
            }
            
            ++pt1;
        }
        
        return ans;
    }
}