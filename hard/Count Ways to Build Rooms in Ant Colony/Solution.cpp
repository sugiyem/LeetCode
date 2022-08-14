class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        // basically n!/(products of size_of_subtree_rooted_at(i))
        int n = prevRoom.size();
        subtree = vector<vector<int>>(n);
        long long factorial = 1;
        
        for (int i = 1; i < n; i++) {
            subtree[prevRoom[i]].push_back(i);
            factorial = factorial * (i + 1) %  MOD;
        }
        
        findSizeOfSubtree(0);
        cout << subtreeProducts << endl;
        return factorial * inverseMod(subtreeProducts) % MOD;
    }
private:
    int MOD = 1e9 + 7;
    long long subtreeProducts = 1;
    vector<vector<int>> subtree;
    
    int inverseMod(long long x) {
        int exp = MOD - 2;
        long long ans = 1;
        
        while(exp) {
            if (exp & 1) ans = ans * x % MOD;
            
            x = x * x % MOD;
            exp >>= 1;
        }
        
        return ans % MOD;
    }
    
    int findSizeOfSubtree(int x) {
        if (x >= subtree.size() || x < 0) return 0;
        
        int ans = 1;
        
        for (int i : subtree[x]) {
            ans += findSizeOfSubtree(i);
        }
        
        subtreeProducts = subtreeProducts * ans % MOD;
        return ans;
    }
};