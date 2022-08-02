class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < nums.length; ++i) {
            set.add(nums[i]);
        }
        
        int ans = 0;
        for (Integer k : set) {
            if (!set.contains(k - 1)) {
                int currElement = k;
                int currLength = 1;
                
                while(set.contains(currElement + 1)) {
                    ++currLength;
                    ++currElement;
                }
                
                ans = Math.max(ans, currLength);
            }
        }
        
        return ans;
    }
}