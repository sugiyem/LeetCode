class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // Greedy algorithm seems to work
        // Kinda difficult to prove tho
        
        int ans = 0, n = row.size();
        vector<int> location(n);
        
        for (int i = 0; i < n; i++) {
            location[row[i]] = i;
        }
        
        for (int i = 0; i < n; i+= 2) {
            int targetNeighbor = row[i] & 1 ? row[i] - 1 : row[i] + 1;
            int currNeighbor = row[i + 1];
            
            if (currNeighbor != targetNeighbor) {
                // row[i + 1] = targetNeighbor;
                row[location[targetNeighbor]] = currNeighbor;
                location[currNeighbor] = location[targetNeighbor];
                // location[targetNeighbor] = i + 1;
                ans++;
            }
        }
        
        return ans;
    }
};