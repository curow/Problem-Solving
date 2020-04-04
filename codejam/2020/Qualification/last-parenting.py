def no_overlap(one, another):
    # if one's start is after another's end or
    # another's start is after one's end
    return one[0] >= another[1] or another[0] >= one[1]

T = int(input())
for _ in range(1, T + 1):
    N = int(input())
    result = ''
    done = False
    intervals = []
    Cs = []
    Js = []
    for __ in range(N):
        interval = list(map(int, input().split()))
        intervals.append(interval)
    sorted_intervals = sorted(intervals)
    for another in sorted_intervals:
        if all([no_overlap(one, another) for one in Cs]):
            Cs.append(another)
        elif all([no_overlap(one, another) for one in Js]):
            Js.append(another)
        else:
            result = 'IMPOSSIBLE'
            break
    if result != 'IMPOSSIBLE':
        for interval in intervals:
            if interval in Cs:
                result += 'C'
            else:
                result += 'J'
    print("Case #{}: {}".format(_, result))

