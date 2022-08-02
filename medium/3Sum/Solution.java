class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        int index = 0;
        
        while(index < len) {
            int left = index + 1;
            int right = len - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] < -nums[index]) {
                    ++left;
                } else if (nums[left] + nums[right] > -nums[index]) {
                    --right;
                } else {
                    ans.add(List.of(nums[index], nums[left], nums[right]));
                    
                    while (left + 1 < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    
                    while (right - 1 > left && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    
                    ++left;
                    --right;
                }
            }
            
            while(index + 1 < len && nums[index] == nums[index + 1]) {
                ++index;
            }
            
            ++index;
        }
        
        return ans;
    }
}