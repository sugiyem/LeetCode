class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) {
            return ans;
        }
        auto compare = [&nums1, &nums2](pair<int, int> x, pair<int, int> y) {
            return nums1[x.first] + nums2[x.second] - nums1[y.first] - nums2[y.second] > 0;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            pq.emplace(make_pair(i, 0));
        }
        while(!pq.empty() && k--) {
            pair<int, int> curr = pq.top();
            pq.pop();
            ans.push_back({nums1[curr.first], nums2[curr.second]});
            if (curr.second == nums2.size() - 1) {
                continue;
            }
            pq.emplace(make_pair(curr.first, curr.second + 1));
        }
        return ans;
    }
};