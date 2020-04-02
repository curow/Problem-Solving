from itertools import product

def get_int_list():
    return list(map(int, input().split()))

T = int(input())
for _ in range(1, T + 1):
    N, K, P = get_int_list()
    weights = []
    for __ in range(N):
        lst = get_int_list()
        for i in range(1, K):
            lst[i] += lst[i - 1]
        weights.append(lst)
    max_weights = 0
    decisions = product(range(K + 1), repeat=N)
    for d in decisions:
        if sum(d) != P:
            continue
        total_weights = 0
        for i in range(N):
            if d[i] == 0:
                continue
            total_weights += weights[i][d[i] - 1]
        if total_weights > max_weights:
            max_weights = total_weights
    print("Case #{}: {}".format(_, max_weights))