import random
from datetime import datetime
from random import randrange
random.seed(datetime.now())

T = int(1e5)
N = 12
MAX = int(1e9)
x = lambda : randrange(1, MAX + 1)
print(T)
for _ in range(T):
    n = randrange(1, N + 1)
    print(n)
    for _ in range(n):
        print("{} {}".format(x(), x()))
