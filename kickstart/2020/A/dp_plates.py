def get_int_list():
    return list(map(int, input().split()))

T = int(input())
for _ in range(1, T + 1):
    N, K, P = get_int_list()
    sums = [[0 for x in range(K + 1)] for y in range(N + 1)]
    for i in range(1, N + 1):
        lst = get_int_list()
        sums[i][1] = lst[0]
        for j in range(1, K):
            lst[j] += lst[j - 1]
            sums[i][j + 1] = lst[j]
    dp = [[0 for x in range(P + 1)] for y in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(P + 1):
            for x in range(min(K, j) + 1):
                dp[i][j] = max(dp[i][j], sums[i][x] + dp[i - 1][j - x])
    print("Case #{}: {}".format(_, dp[N][P]))