T = int(input())
def get_int_list():
    return list(map(int, input().split()))
for _ in range(1, T + 1):
    N, B = get_int_list()
    lst = get_int_list()
    lst = sorted(lst)
    cost = 0
    number = 0
    for i in lst:
        if cost + i <= B:
            number += 1
            cost += i
        else:
            break
    print("Case #{}: {}".format(_, number))
