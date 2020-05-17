T = int(input())
for t in range(1, T + 1):
    n, m = [int(s) for s in input().split(" ")]
    print("Case #{}: {} {}".format(t, n + m, n * m))