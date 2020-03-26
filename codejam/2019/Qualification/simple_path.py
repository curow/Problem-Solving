def inverse(path):
    inversed = ''
    for direction in path:
        if direction == 'E':
            inversed += 'S'
        else:
            inversed += 'E'
    return inversed

T = int(input())
for i in range(1, T + 1):
    N = int(input())
    path = input()
    print("Case #{}: {}".format(i, inverse(path)))

