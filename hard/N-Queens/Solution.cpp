class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> config(n, string(n, '.'));
        backtrack(config, 0);
        return ans;
    }
private:
    vector<vector<string>> ans;
    
    bool isValid(vector<string>& config, int row, int col) {
        int n = config.size();
        
        for (int i = 0; i < n; i++) {
            if (config[i][col] == 'Q') return false;
            if (min(row, col) >= i && config[row - i][col - i] == 'Q') return false;
            if (row >= i && col < n - i && config[row - i][col + i] == 'Q') return false;
        }
        
        return true;
    }
    
    void backtrack(vector<string>& config, int row) {
        int n = config.size();
        
        if (row == n) {
            ans.push_back(config);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(config, row, i)) {
                config[row][i] = 'Q';
                backtrack(config, row + 1);
                config[row][i] = '.';
            }
        }
    }
};