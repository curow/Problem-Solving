T = int(input())
for t in range(1, T + 1):
    n, k = [int(s) for s in input().split(" ")]
    array = [int(s) for s in input().split(" ")]
    count = 0
    index = 0
    while index <= n - k:
        find = False
        for i in range(index, n - k + 1):
            if array[i] == k:
                find = True
                index = i
                break
        if find:
            find_countdown = True
            for i, num in enumerate(reversed(range(1, k + 1))):
                if array[index + i] != num:
                    find_countdown = False
                    break
            if find_countdown:
                count += 1
                index += k
            else:
                index += 1
        else:
            break
    print("Case #{}: {}".format(t, count))