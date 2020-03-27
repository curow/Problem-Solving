import string
def int_stream(start, end):
    num = start
    while num <= end:
        yield num
        num += 1

def prime_stream(stream):
    first = next(stream)
    yield first
    yield from prime_stream(filter(lambda x: x % first, stream))

T = int(input())
for i in range(1, T + 1):
    N = int(input())
    L = int(input())
    stream = int_stream(3, N)
    primes = prime_stream(stream)
    for char in string.ascii_uppercase:
        print("{}: {}".format(char, next(primes)))