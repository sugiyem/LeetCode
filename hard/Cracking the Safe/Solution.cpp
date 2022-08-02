class Solution {
    // By De Bruijn Sequence, such string exists
public:
    string crackSafe(int n, int k) {
        int length = pow(k, n);
        unordered_set<string> vis;
        string ans(n, '0');
        vis.insert(ans);
        
        backtrack(ans, vis, n, k, length);
        
        return ans;
    }
private:
    bool backtrack(string& curr, unordered_set<string>& visited, int n, int k, int len) {
        if (visited.size() == len) return true;
        
        for (int i = 0; i < k; i++) {
            curr.push_back('0' + i);
            string now = curr.substr(curr.size() - n);
            
            if (visited.find(now) == visited.end()) {
                visited.insert(now);
                if (backtrack(curr, visited, n, k, len)) return true;
                visited.erase(now);
            }
            
            curr.pop_back();
        }
        
        return false;
    }
};