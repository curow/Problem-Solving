from itertools import product
def no_overlap(one, another):
    # if one's start is after another's end or
    # another's start is after one's end
    return one[0] >= another[1] or another[0] >= one[1]

def has_overlap(one, another):
    return not no_overlap(one, another)

def is_valid_schedue(schedue):
    N = len(schedue)
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            if has_overlap(schedue[i], schedue[j]):
                return False
    return True

T = int(input())
for _ in range(1, T + 1):
    N = int(input())
    intervals = []
    for __ in range(N):
        interval = list(map(int, input().split()))
        intervals.append(interval)
    decisions = product((0, 1), repeat=N)
    good_decision = None
    for decision in decisions:
        Cs, Js = [], []
        for i, interval in enumerate(intervals):
            if decision[i] == 1:
                Cs.append(interval)
            else:
                Js.append(interval)
        if is_valid_schedue(Cs) and is_valid_schedue(Js):
            good_decision = decision
            break
    if good_decision:
        result = ''
        for i in good_decision:
            result += 'C' if i else 'J'
    else:
        result = 'IMPOSSIBLE'
    print("Case #{}: {}".format(_, result))

