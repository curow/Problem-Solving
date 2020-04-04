import random
T = random.randint(1, 100)
print(T)
for _ in range(T):
    N = random.randint(2, 10)
    print(N)
    for __ in range(N):
        start = random.randint(0, 24 * 60 - 1)
        end = random.randint(start + 1, 24 * 60)
        print(start, end)