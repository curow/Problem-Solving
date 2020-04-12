def get_int_list():
    return list(map(int, input().split()))

def average_level(matrix, i, j):
    R = len(matrix)
    C = len(matrix[0])
    total_level = 0
    number_neighbor = 0
    for nj in range(j - 1, -1, -1):
        if matrix[i][nj] != -1:
            number_neighbor += 1
            total_level += matrix[i][nj]
            break
    for nj in range(j + 1, C):
        if matrix[i][nj] != -1:
            number_neighbor += 1
            total_level += matrix[i][nj]
            break
    for ni in range(i - 1, -1, -1):
        if matrix[ni][j] != -1:
            number_neighbor += 1
            total_level += matrix[ni][j]
            break
    for ni in range(i + 1, R):
        if matrix[ni][j] != -1:
            number_neighbor += 1
            total_level += matrix[ni][j]
            break
    if number_neighbor != 0:
        return total_level / number_neighbor   
    else:
        return 0

def round_interest(matrix):
    total = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] != -1:
                total += matrix[i][j]
    return total
    
def compete(matrix):
    eliminated = []
    R = len(matrix)
    C = len(matrix[0])
    for i in range(R):
        for j in range(C):
            if matrix[i][j] != -1:
                val = average_level(matrix, i, j)
                if val > matrix[i][j]:
                    eliminated.append((i, j))
    for i, j in eliminated:
        matrix[i][j] = -1
    interest = round_interest(matrix)
    finished = False if eliminated else True
    return finished, interest

T = int(input())
for t in range(T):
    R, C = get_int_list()
    matrix = []
    for i in range(R):
        row = get_int_list()
        matrix.append(row)
    total_interest = round_interest(matrix)
    # print(total_interest)
    # print(matrix)
    # print('i=0,j=1: {}'.format(average_level(matrix, 0, 1)))
    finished = False
    while not finished:
        finished, interest = compete(matrix)
        # print(interest)
        # print(matrix)
        if not finished:
            total_interest += interest
    print("Case #{}: {}".format(t + 1, total_interest))