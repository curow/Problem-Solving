import math

def partition(array, start):
    current = start
    end = current + 1
    while end < len(array) and array[current] < array[end]:
        current = end
        end += 1
    return end

T = int(input())
for _ in range(1, T + 1):
    N, B, F = list(map(int, input().split()))
    good = [0] * (N - B)
    for bit in range(5):
        weight = 2**bit
        pattern = '0' * weight + '1' * weight
        num_pattern = math.ceil(N / len(pattern))
        query = (pattern * num_pattern)[:N]
        print(query)
        val = input()
        values = [int(x) for x in val]
        for i, x in enumerate(values):
            good[i] += weight * x
    num_partition = math.ceil(N / 32)
    bad_lst = []
    start = 0
    for i in range(num_partition):
        remain = min(N - i * 32, 32)
        end = partition(good, start)
        if end - start < 32:
            bad = sorted(set(range(remain)) - set(good[start:end]))
            bad = [x + (32 * i) for x in bad]
            bad_lst.extend(bad)
        start = end
    # assert len(bad_lst) == B
    print(*bad_lst)
    judge = int(input())
    if judge == -1:
        break