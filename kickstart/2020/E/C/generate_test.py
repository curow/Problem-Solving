from random import randrange
T = 1000
N = 12
MAX = int(1e9)
x = lambda : randrange(1, MAX + 1)
print(T)
for _ in range(T):
    n = randrange(1, N + 1)
    print(n)
    for _ in range(n):
        print("{} {}".format(x(), x()))
