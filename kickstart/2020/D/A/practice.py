T = int(input())
for t in range(1, T + 1):
    n = int(input())
    v = [int(s) for s in input().split(" ")]
    cnt = 0
    num_breaking = -1
    for i in range(n):
        if v[i] > num_breaking:
            num_breaking = v[i]
            if i == n - 1 or v[i] > v[i + 1]:
                cnt += 1
    print("Case #{}: {}".format(t, cnt))
