offsets = []
for a in (+1, -1):
    for b in (+2, -2):
        offsets.append((a, b))
        offsets.append((b, a))

def solve(k):
    def count(i, j):
        cnt = k * k - 1;
        for di, dj in offsets:
            ni, nj = i + di, j + dj
            if 1 <= ni <= k and 1 <= nj <= k:
                cnt -= 1
        return cnt
    res = 0
    for i in range(1, k + 1):
        for j in range(1, k + 1):
            res += count(i, j)
    return res

n = int(input())
for k in range(1, n + 1):
    print(solve(k))
