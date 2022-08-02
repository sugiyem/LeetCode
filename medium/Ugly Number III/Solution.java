class Solution {
    public long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        }
        
        if (b == 0) {
            return a;
        }
        
        return gcd(b, a % b);
    }
    
    public long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
    
    public long count(long n, long a, long b, long c) {
        return (n/a) + (n/b) + (n/c) - (n/lcm(a,b)) - (n/lcm(b,c)) - (n/lcm(c,a)) 
            + (n/lcm(lcm(a,b),c));
    }
    
    public int nthUglyNumber(int n, int a, int b, int c) {
        long begin = 0;
        long end = Integer.MAX_VALUE;
        
        while(begin < end) {
            long mid = begin + (end - begin) / 2;
            
            if (count(mid, a, b, c) < n) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return (int) begin;
        
    }
}