class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size(), count = 0;
        vector<vector<int>> counter(len + 1);
        vector<int> ans;
        unordered_map<int, int> freq;
        
        for (int i = 0; i < len; i++) {
            freq[nums[i]]++;
        }
        
        for (auto u : freq) {
            count = max(count, u.second);
            counter[u.second].push_back(u.first);
        }
        
        while(ans.size() < k && count > 0) {
            for (int v : counter[count]) {
                ans.push_back(v);
            }
            
            count--;
        }
        
        return ans;
    }
};