n = int(input())
x = 5
cnt = 0
while n >= x:
    cnt += n // x
    x *= 5
print(cnt)

