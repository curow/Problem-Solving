T = int(input())
for t in range(1, T + 1):
    k = int(input())
    v = [int(s) for s in input().split(" ")]

    dp = [[float('inf') for _ in range(4)] for _ in range(k)]

    dp[0] = [0 for _ in range(4)]
    for i in range(1, k):
        if v[i] > v[i - 1]:
            dp[i][0] = min(dp[i - 1][x] for x in range(4)) + 1
            for j in range(1, 4):
                dp[i][j] = min(dp[i - 1][x] for x in range(j))
        elif v[i] < v[i - 1]:
            dp[i][3] = min(dp[i - 1][x] for x in range(4)) + 1
            for j in range(3):
                dp[i][j] = min(dp[i - 1][x] for x in range(j + 1, 4))
        else:
            for j in range(4):
                dp[i][j] = dp[i - 1][j]

    print("Case #{}: {}".format(t, min(dp[k - 1][x] for x in range(4))))
