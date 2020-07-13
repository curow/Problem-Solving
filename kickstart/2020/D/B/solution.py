def dfs(val, start_idx, start_symbol, num_breaking):
    if start_idx >= len(val) - 1:
        return num_breaking
    

    decending = True
    if val[start_idx + 1] > val[start_idx]:
        start_symbol += 1
        decending = False
    elif val[start_idx + 1] < val[start_idx]:
        start_symbol -= 1
    
    has_breaking = False
    if start_symbol > 3 or start_symbol < 0:
        has_breaking = True
        num_breaking += 1

    if has_breaking:
        num_breaking = min(dfs(val, start_idx + 1, x, num_breaking) for x in range(4))
    else:
        if decending:
            num_breaking = min(dfs(val, start_idx + 1, x, num_breaking) for x in range(0, start_symbol + 1))
        else:
            num_breaking = min(dfs(val, start_idx + 1, x, num_breaking) for x in range(start_symbol, 4))


    return num_breaking 
        

t = int(input())
for i in range(1, t + 1):
    k = int(input())
    val = [int(s) for s in input().split(" ")]
    num_breaking = min(dfs(val, 0, x, 0) for x in range(4))
    print("Case #{}: {}".format(i, num_breaking))
