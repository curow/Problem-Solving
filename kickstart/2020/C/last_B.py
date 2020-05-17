T = int(input())
for t in range(1, T + 1):
    R, C = [int(s) for s in input().split(" ")]
    path = ""
    matrix = []
    for i in range(R):
        matrix.append([x for x in input()])
    dependency = {}
    for i in reversed(range(0, R)):
        current_row = matrix[i]
        if i + 1 < R:
            depend_row = matrix[i + 1]
        else:
            depend_row = current_row
        for j in range(C):
            current = current_row[j]
            depend = depend_row[j]
            if current not in dependency:
                dependency[current] = set()
            dependency[current].add(depend)
    dependency = list(dependency.items())
    dependency.sort(key=lambda x: len(x[1]))
    while dependency:
        first_value = dependency[0][0]
        first_depend = dependency[0][1]
        if len(first_depend) > 1 or first_depend.pop() != first_value:
            path = ""
            break
        else:
            path += first_value
            dependency.pop(0)
            for d in dependency:
                if first_value in d[1]:
                    d[1].remove(first_value)
            dependency.sort(key=lambda x: len(x[1]))
    if path:
        print("Case #{}: {}".format(t, path))
    else:
        print("Case #{}: {}".format(t, -1))

    
