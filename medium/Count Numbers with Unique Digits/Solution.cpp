class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        
        int currSum = 10, currAdd = 9, currMultiplier = 9;
        n--;
        
        while(n--) {
            currAdd *= (currMultiplier--);
            currSum += currAdd;
        }
        
        return currSum;
    }
};