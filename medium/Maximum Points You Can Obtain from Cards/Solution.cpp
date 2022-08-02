class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, len = cardPoints.size();
        
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        
        int ans = sum;
        
        for (int i = 0; i < k; i++) {
            sum += cardPoints[len - 1 - i] - cardPoints[k - 1 - i];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};