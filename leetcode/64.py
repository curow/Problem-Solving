class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[float('inf') for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                if i > 0 and j > 0:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
                elif i > 0:
                    dp[i][j] = dp[i - 1][j] + grid[i][j]
                elif j > 0:
                    dp[i][j] = dp[i][j - 1] + grid[i][j]
                else:
                    dp[i][j] = grid[i][j]
        return dp[-1][-1]
                   
        
