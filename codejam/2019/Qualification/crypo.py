import string
import math
def get_int():
    return int(input())
def get_int_list():
    return map(int, input().split())

T = get_int()
for _ in range(1, T + 1):
    lst = []
    N, L = tuple(get_int_list())
    arr = get_int_list()
    first = next(arr)
    second = next(arr)
    common = math.gcd(first, second)
    lst.append(first // common)
    lst.append(common)
    lst.append(second // common)
    for i in range(2, L):
        num = next(arr)
        lst.append(num // lst[-1])
    primes = sorted(set(lst))
    int_to_char = {}
    for i, ch in enumerate(string.ascii_uppercase):
        int_to_char[primes[i]] = ch
    result = ''
    for num in lst:
        result += int_to_char[num]
    print("Case #{}: {}".format(_, result))
    


