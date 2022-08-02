class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> numberOfLoses;
        set<int> players;
        vector<vector<int>> ans(2);
        
        for (auto match : matches) {
            numberOfLoses[match[1]]++;
            players.insert(match[0]);
            players.insert(match[1]);
        }
        
        for (int player : players) {
            if (!numberOfLoses.count(player)) {
                ans[0].push_back(player);
            } else if (numberOfLoses[player] == 1) {
                ans[1].push_back(player);
            }
        }
        
        return ans;
        
        
        
        
    }
};