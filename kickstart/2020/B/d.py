T = int(input())
for t in range(1, T + 1):
    W, H, L, U, R, D = list(map(int, input().split()))
    dp = [[0 for j in range(W)] for i in range(H)]
    dp[0][0] = 1
    for i in range(H):
        for j in range(W):
    print("Case #{}: {}".format(t, dp[-1][-1]))
