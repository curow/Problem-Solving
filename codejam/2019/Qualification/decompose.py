T = int(input())
for i in range(T):
    N = int(input())
    a, b = decompose(N)
    print("Case #{}: {} {}".format(i + 1, a, b))
        
def decompose(N):
    """
    >>> decompose(4)
    (2, 2)
    >>> decompose(940)
    (920, 20)
    >>> decompose(4444)
    (2222, 2222)
    """
    if N == 0:
        return 0, 0
    all_but_last, last = N // 10, N % 10
    a, b = decompose(all_but_last)
    if last == 4:
        a = a * 10 + 2
        b = b * 10 + 2
    else:
        a = a * 10 + last
        b = b * 10
    return a, b