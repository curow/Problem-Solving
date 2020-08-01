x = int(input())
vals = [x]
while x > 1:
    if x % 2 == 0:
        x //= 2
    else:
        x = 3 * x + 1
    vals.append(x)
print(*vals)

