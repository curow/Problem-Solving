t = int(input())
for i in range(1, t + 1):
    n, m = [int(s) for s in input().split(" ")]
    print("Case #{}: {} {}".format(i, n + m, n * m))