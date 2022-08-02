class Solution {
    public int singleNumber(int[] nums) {
        // hashmap
        Set<Integer> s = new HashSet<>();
        int currSum = 0;
        int uniqueSum = 0;
        
        for (int i = 0; i < nums.length; ++i) {
            if (!s.contains(nums[i])) {
                uniqueSum += nums[i];
                s.add(nums[i]);
            }
            currSum += nums[i];
        }
        
        return 2 * uniqueSum - currSum;
    }
}