T = int(input())
for t in range(1, T + 1):
    N = int(input())
    array = list(map(int, input().split()))
    count = 0
    i = 1
    while i < N - 1:
        if array[i] > array[i - 1] and array[i] > array[i + 1]:
            count += 1
        i += 1
    print("Case #{}: {}".format(t, count))
