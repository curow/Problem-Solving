T = int(input())
for t in range(1, T + 1):
    n, q = [int(s) for s in input().split(" ")]
    doors = [float('inf')] + [int(s) for s in input().split(" ")] + [float('inf')]
    ans = []
    for _ in range(q):
        s, k = [int(s) for s in input().split(" ")]
        cnt = 1
        left = doors[s - 1]
        right = doors[s]
        while cnt <= n:
            if cnt == k:
                ans.append(s)
                break
            if left == float('inf') and right == float('inf'):
                break

            if left < right:
                s -= 1
                left = doors[s - 1]
            else:
                s += 1
                right = doors[s]
            cnt += 1
    print("Case #{}: {}".format(t, ans))
