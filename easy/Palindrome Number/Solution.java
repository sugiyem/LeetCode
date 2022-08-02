class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int curr = x;
        int reverse = 0;
        while(curr > 0) {
            reverse = reverse * 10 + (curr % 10);
            curr /= 10;
        }
        
        return reverse == x;
    }
}