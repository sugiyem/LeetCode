class Solution {
    public int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }
        
        if (b == 0) {
            return a;
        }
        
        return gcd(b, a % b);
    }
    
    public boolean isGoodArray(int[] nums) {
        if (nums.length == 0) {
            return false;
        }
        
        if (nums.length == 1) {
            return nums[0] == 1;
        }
        
        int currGCD = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            currGCD = gcd(nums[i], currGCD);
            if (currGCD == 1) {
                return true;
            }
        }
        
        return currGCD == 1;
    }
}