from functools import lru_cache

T = int(input())
for t in range(1, T + 1):
    k = int(input())
    v = [int(s) for s in input().split(" ")]

    @lru_cache(maxsize=None)
    def dfs(start_idx, start_symbol, num_breaking):
        if start_idx >= len(v) - 1:
            return num_breaking

        if v[start_idx + 1] > v[start_idx]:
            decending = False
            start_symbol += 1
        elif v[start_idx + 1] < v[start_idx]:
            decending = True
            start_symbol -= 1
        else:
            return dfs(start_idx + 1, start_symbol, num_breaking)

        if start_symbol > 3 or start_symbol < 0:
            return min(dfs(start_idx + 1, x, num_breaking + 1) for x in range(4))
        else:
            if decending:
                return min(dfs(start_idx + 1, x, num_breaking) for x in range(0, start_symbol + 1))
            else:
                return min(dfs(start_idx + 1, x, num_breaking) for x in range(start_symbol, 4))

    print("Case #{}: {}".format(t, min(dfs(0, x, 0) for x in range(4))))
