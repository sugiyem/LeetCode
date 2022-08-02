class Solution {
    public int reverse(int x) {
        long ans = 0;
        int y = Math.abs(x);
        while(y != 0){
            ans = ans * 10 + (y % 10);
            y /= 10;
        }
        if (ans < Integer.MIN_VALUE || ans > Integer.MAX_VALUE) {
            ans = 0;
        }
        if (x < 0) {
            ans *= -1;
        }
        return (int)ans;
    }
}