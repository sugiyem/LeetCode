class Solution {
public:
    int lastRemaining(int n) {
        int curr = 1, dist = 1, status = 1;
       
        while (n > 1) {
            if (status) {
                curr += dist;
            } else {
                curr += (n & 1 ? dist : 0);
            }
            
            status = 1 - status;
            dist *= 2;
            n /= 2;
        }
        
        return curr;
    }
};