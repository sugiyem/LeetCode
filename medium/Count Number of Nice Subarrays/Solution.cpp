class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, start = 0, oddCount = 0, currCount = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                oddCount++;
                
                if (oddCount == k) {
                    currCount = 0;
                    while (oddCount == k) {
                        if (nums[start] & 1) {
                            oddCount--;
                        }

                        start++;
                        currCount++;
                    }
                    
                }
            }
            
            ans += currCount;
        }
        
        return ans;
    }
};