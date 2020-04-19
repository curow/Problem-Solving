T = int(input())
for t in range(1, T + 1):
    N, D = list(map(int, input().split()))
    array = list(map(int, input().split()))
    for num in reversed(array):
        D = (D // num) * num
    print("Case #{}: {}".format(t, D))
