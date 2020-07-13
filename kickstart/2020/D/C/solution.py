T = int(input())
for t in range(1, T + 1):
    n, a, b = [int(s) for s in input().split(" ")]
    parent = [0, 0]
    if n > 1:
        parent += [int(s) for s in input().split(" ")]
    else:
        input()
    ans = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            visited = {i, j}
            def travel_every_kth(start, k):
                cnt = 0
                visited.add(start)
                while parent[start] != 0:
                    start = parent[start]
                    cnt += 1
                    if cnt == k:
                        visited.add(start)
                        cnt = 0
            travel_every_kth(i, a)
            travel_every_kth(j, b)
            ans += len(visited)
            
    ans /= n * n
    print("Case #{}: {}".format(t, ans))
