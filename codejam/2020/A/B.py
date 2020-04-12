S = 500
pascal = [[0 for i in range(S)] for j in range(S)]
pascal[0][0] = 1
for i in range(1, S):
    for j in range(i + 1):
        if j - 1 >= 0:
            pascal[i][j] += pascal[i - 1][j - 1] 
        pascal[i][j] += pascal[i - 1][j]
# for i in range(5):
#     for j in range(S):
#         if pascal[i][j] != 0:
#             print(pascal[i][j], end=' ')
#     print()
T = int(input())
for t in range(T):
    N = int(input())
    visited = [[False for i in range(S)] for j in range(S)]
    print("Case #{}:".format(t + 1))