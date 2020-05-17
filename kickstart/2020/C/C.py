from functools import lru_cache
@lru_cache(maxsize=None)
def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

@lru_cache(maxsize=None)
def square(n):
    return n * n

T = int(input())
for t in range(1, T + 1):
    N = int(input())
    array = [int(s) for s in input().split(" ")]
    count = 0
    for i in range(N):
        s = 0
        for j in range(i, N):
            s += array[j]
            if s >= 0:
                x = isqrt(s)
                if square(x) == s:
                    count += 1
    print("Case #{}: {}".format(t, count))