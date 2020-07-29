class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n, vector<int>(m));
        f[0][0] = grid[0][0];
        for (int j = 1; j < m; ++j) f[0][j] = f[0][j - 1] + grid[0][j];
        for (int i = 1; i < n; ++i) f[i][0] = f[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[n - 1][m - 1];
    }
};
