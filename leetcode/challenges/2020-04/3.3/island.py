class UnionFind:
    def __init__(self, size):
        self.array = [-1] * size

    def sizeof(self, x):
        rx = self.find(x)
        return -self.array[rx]

    def union(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb:
            return
        elif self.sizeof(ra) > self.sizeof(rb):
            self.array[ra] += self.array[rb]
            self.array[rb] = ra
        else:
            self.array[rb] += self.array[ra]
            self.array[ra] = rb

    def find(self, x):
        if self.array[x] < 0:
            return x
        else:
            rx = self.find(self.array[x])
            self.array[x] = rx
            return rx

    def num_sets(self):
        count = 0
        for x in self.array:
            if x < 0:
                count += 1
        return count

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        u = UnionFind(rows * cols + 1)
        water_index = rows * cols
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == '0':
                    u.union(water_index, i * cols + j)
                else:
                    for di, dj in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                        ai, aj = i + di, j + dj
                        if rows > ai >= 0 and cols > aj >= 0 and grid[ai][aj] == '1':
                            u.union(ai * cols + aj, i * cols + j)
        return u.num_sets() - 1
