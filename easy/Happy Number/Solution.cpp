class Solution {
public:
    bool isHappy(int n) {
        int slowSequence = n;
        int fastSequence = nextElement(n);
        
        while(slowSequence != fastSequence) {
            slowSequence = nextElement(slowSequence);
            fastSequence = nextElement(nextElement(fastSequence));
        }
        
        return slowSequence == 1;
    }
private:
    int nextElement(int n) {
        int ans = 0;
        
        while(n) {
            ans += pow(n % 10, 2);
            n /= 10;
        }
        
        return ans;
    }
};