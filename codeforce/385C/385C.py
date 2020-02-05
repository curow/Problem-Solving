def list_input():
    return list(map(int, input().split()))

def int_input():
    return int(input())

def find_primes(l, r):
    def is_prime(x):
        from math import sqrt
        if x < 2:
            return False
        return all([x % k for k in range(2, int(sqrt(x)) + 1)])
    lst = []
    for i in range(l, r+1):
        if is_prime(i):
            lst.append(i)
    return lst

def ans(lst, primes):
    total = 0
    for num in lst:
        for p in primes:
            if num % p == 0:
                total += 1
    return total

def main():
    n = int_input()
    lst = list_input()
    m = int_input()
    # print(n)
    # print(lst)
    # print(m)
    for _ in range(m):
        l, r = list_input()
        # print(l, r)
        primes = find_primes(l, r)
        # print("primes: {}".format(primes))
        print(ans(lst, primes))

main()
