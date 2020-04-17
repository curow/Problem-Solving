class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def search(i, j):
            grid[i][j] = '#'
            for di, dj in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                ai, aj = i + di, j + dj
                if rows > ai >= 0 and cols > aj >= 0 and grid[ai][aj] == '1':
                    search(ai, aj)
        if not grid:
            return 0
        count = 0
        rows = len(grid)
        cols = len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == '1':
                    count += 1
                    search(i, j)
        return count
