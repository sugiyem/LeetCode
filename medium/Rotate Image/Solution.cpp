class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int i = 0; i <= n / 2; i++) {
            for (int j = 0; j < n - 2 * i; j++) {
                swap(matrix[i][i + j], matrix[i + j][n - i]);
                swap(matrix[i][i + j], matrix[n - i][n - i - j]);
                swap(matrix[i][i + j], matrix[n - i - j][i]);
            }
        }
    }
};