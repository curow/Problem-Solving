import string
import math

def get_int():
    return int(input())

def get_int_list():
    return list(map(int, input().split()))

def isqrt(n):
    if n < 2:
        return n
    else:
        small = isqrt(n >> 2) << 1
        large = small + 1
        if large * large > n:
            return small
        else:
            return large

T = get_int()
for _ in range(1, T + 1):
    primes = []
    N, L = tuple(get_int_list())
    products = get_int_list()
    primes = [0 for _ in range(L + 1)]
    index = 0
    for i in range(L - 1):
        if products[i] != products[i + 1]:
            index = i
            break
    common = math.gcd(products[index], products[index + 1])
    primes[index + 1] = common
    for i in range(index, -1, -1):
        num = products[i]
        primes[i] = num // primes[i + 1]
    for i in range(index + 2, L + 1):
        num = products[i - 1]
        primes[i] = num // primes[i - 1]
    sorted_primes = sorted(set(primes))
    int_to_char = {}
    for i, ch in enumerate(string.ascii_uppercase):
        int_to_char[sorted_primes[i]] = ch
    result = ''
    for num in primes:
        result += int_to_char[num]
    print("Case #{}: {}".format(_, result))
    


