def get_int_list():
    return list(map(int, input().split()))

def column(matrix, col):
    return [row[col] for row in matrix]

T = int(input())
for _ in range(1, T + 1):
    N = int(input())
    matrix = [[0 for j in range(N)] for i in range(N)]
    n_set = set(range(1, N + 1))
    k, r, c = 0, 0, 0
    for i in range(N):
        lst = get_int_list()
        for j in range(N):
            matrix[i][j] = lst[j]
        k += matrix[i][i]
        if n_set - set(matrix[i][:]):
            r += 1
    for j in range(N):
        if n_set - set(column(matrix, j)):
            c += 1
    print("Case #{}: {} {} {}".format(_, k, r, c))