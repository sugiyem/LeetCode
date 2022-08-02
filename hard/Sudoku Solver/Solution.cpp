class Solution {
private:
    bool solve(vector<vector<char>>& v) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (v[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (valid(v, i, j, c)) {
                            v[i][j] = c;
                            if (solve(v)) {
                                return true;
                            } else {
                                v[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool valid(vector<vector<char>>& v, int i, int j, char c) {
        for (int x = 0; x < 9; ++x) {
            if (v[x][j] != '.' && v[x][j] == c) {
                return false;
            }
            if (v[i][x] != '.' && v[i][x] == c) {
                return false;
            }
            if (v[3 * (i / 3) + x / 3][ 3 * (j / 3) + x % 3] != '.' && 
               v[3 * (i / 3) + x / 3][ 3 * (j / 3) + x % 3] == c) {
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};