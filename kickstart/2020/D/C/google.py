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

    def dfs(visit_count, num_skip):
        path_taken = []
        visited = [False for _ in range(n)]
        stack = []
        stack.append(0)
        while stack:
            idx = stack[-1]
            if not visited[idx]:
                path_taken.append(idx)
                # dfs deeper if idx has children
                if idx in children:
                    for x in children[idx]:
                        stack.append(x)
                visited[idx] = True
            else:
                stack.pop()
                path_taken.pop()
                visit_count[idx] += 1
                if len(path_taken) >= num_skip:
                    prev = path_taken[-num_skip]
                    visit_count[prev] += visit_count[idx]

    def visit_possibility(num_skip):
        visit_count = [0 for _ in range(n)]
        dfs(visit_count, num_skip)
        return [visit_count[i] / n for i in range(n)]

    pa = visit_possibility(a)
    pb = visit_possibility(b)

    expected_val = 0
    for i in range(n):
        expected_val += pa[i] + pb[i] - pa[i] * pb[i]

    print("Case #{}: {}".format(t, expected_val))
