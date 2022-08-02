class Solution {
    public int divide(int dividend, int divisor) {
        ArrayList<Long> powers = new ArrayList<>();
        ArrayList<Long> pow2 = new ArrayList<>();
        long absDivisor = divisor == Integer.MIN_VALUE ? 2147483648L : Math.abs(divisor);
        long absDividend = dividend == Integer.MIN_VALUE ? 2147483648L : Math.abs(dividend);
        long pow = absDivisor;
        long two = 1;
        
        while(pow <= absDividend) {
            powers.add(pow);
            pow2.add(two);
            pow += pow;
            two += two;
        }
        
        long curr = absDividend;
        long ans = 0;
        
        for (int i = powers.size() - 1; i >= 0; --i) {
            if (curr >= powers.get(i)) {
                ans += pow2.get(i);
                curr -= powers.get(i);
            }
        }
        
        if (divisor != absDivisor && dividend == absDividend) {
            ans = -ans;
        }
        
        if (divisor == absDivisor && dividend != absDividend) {
            ans = -ans;
        }
        
        if (ans >= Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }
        
        if (ans <= Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }
        
        return (int) ans;
    }
}