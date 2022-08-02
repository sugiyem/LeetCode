class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<Character> check = new HashSet<>();
        
        for (int i = 0; i < 9; ++i) {
            check.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (check.contains(board[i][j])) {
                        return false;
                    }
                    check.add(board[i][j]);
                }
            }
        }
        
        for (int i = 0; i < 9; ++i) {
            check.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (check.contains(board[j][i])) {
                        return false;
                    }
                    check.add(board[j][i]);
                }
            }
        }
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                check.clear();
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (board[3 * i + x][3 * j + y] != '.') {
                            if (check.contains(board[3 * i + x][3 * j + y])) {
                                return false;
                            }
                            check.add(board[3 * i + x][3 * j + y]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
}