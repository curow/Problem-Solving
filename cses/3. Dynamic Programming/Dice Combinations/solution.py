n = int(input())
f = [0] * (n + 1)
f[0] = 1
for i in range(1, n + 1):
    for j in range(1, 7):
        if i - j >= 0:
            f[i] = (f[i] + f[i - j]) % (10**9 + 7)
print(f[n])
