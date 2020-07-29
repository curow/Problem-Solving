class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        f[0][0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j < m; ++j) {
            if (obstacleGrid[0][j] == 0) {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] == 0) {
                f[i][0] = f[i - 1][0];
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[n - 1][m - 1];
    }
};
