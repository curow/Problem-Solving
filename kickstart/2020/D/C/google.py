T = int(input())
for t in range(1, T + 1):
    n, a, b = [int(s) for s in input().split(" ")]
    if n > 1:
        parent = [-1] + [int(s) - 1 for s in input().split(" ")]
    else:
        input()
        print("Case #{}: {}".format(t, 1.0))
        continue
        
    children = {}
    for child, p in enumerate(parent):
        if p not in children:
            children[p] = [child]
        else:
            children[p].append(child)


    def visit_possibility(num_skip):
        path_taken = []
        def dfs(idx, visit_count, num_skip):
            # dfs deeper if idx has children
            if idx in children:
                path_taken.append(idx)
                for x in children[idx]:
                    dfs(x, visit_count, num_skip)
                path_taken.pop()

            visit_count[idx] += 1

            if len(path_taken) >= num_skip:
                prev = path_taken[-num_skip]
                visit_count[prev] += visit_count[idx]

        visit_count = [0 for _ in range(n)]
        dfs(0, visit_count, num_skip)
        return [visit_count[i] / n for i in range(n)]

    pa = visit_possibility(a)
    pb = visit_possibility(b)

    expected_val = 0
    for i in range(n):
        expected_val += pa[i] + pb[i] - pa[i] * pb[i]

    print("Case #{}: {}".format(t, expected_val))
