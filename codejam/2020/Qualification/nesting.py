LEFT = '('
RIGHT = ')'
T = int(input())
for _ in range(1, T + 1):
    s = input()
    digits = list(map(int, [x for x in s]))
    prev = 0
    result = ''
    remain = 0
    for i in digits:
        current = i
        if prev < current:
            left = LEFT * (current - prev)
            result += left
            remain += len(left)
        elif prev > current:
            right = RIGHT * (prev - current)
            result += right
            remain -= len(right)
        result += str(i)
        prev = current
    result += remain * RIGHT
    print("Case #{}: {}".format(_, result))
