def list_input():
    return list(map(int, input().split()))

def int_input():
    return int(input())

prime_number = {}
def find_primes(l, r):
    def is_prime(x):
        from math import sqrt
        if x < 2:
            return False
        elif x in prime_number:
            return prime_number[x]
        else:
            prime_number[x] = all([x % k for k in range(2, int(sqrt(x)) + 1)])
            return prime_number[x]
    lst = []
    for i in range(l, r+1):
        if is_prime(i):
            lst.append(i)
    return lst

def main():
    answers = {}
    def solve(primes):
        total = 0
        for p in primes:
            if p not in answers:
                answers[p] = sum([x % p == 0 for x in lst])
            total += answers[p]
        return total
    n = int_input()
    lst = list_input()
    m = int_input()
    for _ in range(m):
        l, r = list_input()
        primes = find_primes(l, r)
        print(solve(primes))

main()
