class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        int end = x, start = 1;
        while(start < end) {
            int mid = start + ((end - start) >> 1);
            if (mid > x / mid) {
                end = mid - 1;
            } else if (mid + 1 > x / (mid + 1)) {
                return mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};