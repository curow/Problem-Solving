t = int(input())
for i in range(1, t + 1):
    n = int(input())
    v = [int(s) for s in input().split(" ")]
    cnt = 0
    breaking_num = -1
    for j in range(n):
        if v[j] > breaking_num:
            breaking_num = v[j]
            if j == n - 1 or v[j + 1] < v[j]:
                cnt += 1
    print("Case #{}: {}".format(i, cnt))

