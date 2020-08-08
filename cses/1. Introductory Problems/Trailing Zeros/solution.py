n = int(input())
def f(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res
res = f(n)
ans = 0
while res % 10 == 0:
    ans += 1
    res //= 10
print(ans)

