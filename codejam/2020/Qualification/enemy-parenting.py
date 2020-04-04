def no_overlap(one, another):
    # if one's start is after another's end or
    # another's start is after one's end
    return one[0] >= another[1] or another[0] >= one[1]

def has_overlap(one, another):
    return not no_overlap(one, another)

def separable(current_index, decision, value, from_index, conflict_map):
    if decision[current_index] != 0:
        return decision[current_index] == value
    decision[current_index] = value
    neighbors = conflict_map[current_index]
    for i in range(len(neighbors)):
        if neighbors[i] == True and i != from_index:
            if not separable(i, decision, -value, current_index, conflict_map):
                return False
    return True


T = int(input())
for _ in range(1, T + 1):
    N = int(input())
    intervals = []
    for i in range(N):
        interval = tuple(map(int, input().split()))
        intervals.append(interval)
    conflict_map = [[False for a in range(N)] for b in range(N)]
    for b in range(N):
        for a in range(b + 1, N):
            if has_overlap(intervals[a], intervals[b]):
                conflict_map[a][b] = True
                conflict_map[b][a] = True
    decision = [0 for x in range(N)]
    has_solution = True
    for i in range(N):
        if decision[i] == 0 and \
                not separable(i, decision, 1, i, conflict_map):
            has_solution = False
    if has_solution:
        result = ''
        for i in decision:
            result += 'J' if i >= 0 else 'C'
    else:
        result = 'IMPOSSIBLE'
    print("Case #{}: {}".format(_, result))

