def sanity_check(lst):
    end = 0
    for item in lst:
        if item[0] < end:
            return False
        end = item[-1]
    return True
T = int(input())
for _ in range(1, T + 1):
    N = int(input())
    result = ''
    done = False
    C_set = set()
    J_set = set()
    C_list = []
    J_list = []
    I_list = []
    for __ in range(N):
        start, end = list(map(int, input().split()))
        if done:
            continue
        overlap_with_C = False
        overlap_with_J = False
        for minute in range(start, end):
            if minute in C_set:
                overlap_with_C = True
                if overlap_with_J:
                    break
            if minute in J_set:
                overlap_with_J = True
                if overlap_with_C:
                    break
        if overlap_with_C and overlap_with_J:
            result = 'IMPOSSIBLE'
            I_list.append([start, end])
            done = True
        elif overlap_with_C:
            result += 'J'
            J_list.append([start, end])
            for minute in range(start, end):
                J_set.add(minute)
        else:
            result += 'C'
            C_list.append([start, end])
            for minute in range(start, end):
                C_set.add(minute)
    # C_list = sorted(C_list)
    # J_list = sorted(J_list)
    # print("C:", C_list)
    # print("J:", J_list)
    # print("I:", I_list)
    # assert sanity_check(C_list)
    # assert sanity_check(J_list)
    print("Case #{}: {}".format(_, result))
    # print()

