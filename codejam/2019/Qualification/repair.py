import math

def get_int_list():
    return list(map(int, input().split()))

T = int(input())
for _ in range(1, T + 1):
    N, B, F = get_int_list()
    bits = int(math.ceil(math.log2(N)))
    # assert bits <= F
    good = [0] * (N - B)
    for bit in range(bits):
        weight = 2**bit
        pattern = '0' * weight + '1' * weight
        num_pattern = int(math.ceil(N / len(pattern)))
        query = (pattern * num_pattern)[:N]
        # assert len(query) == N
        # assert all([x in '01' for x in query])
        print(query)
        val = input()
        values = [int(x) for x in val]
        for i, x in enumerate(values):
            good[i] += weight * x
    bad = set(range(N)) - set(good)
    bad = sorted(bad)
    print(*bad)
    judge = int(input())
    if judge == -1:
        break