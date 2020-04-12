def find_match(patterns):
    has_match = True
    s = []
    for p in patterns:
        if not has_match:
            break
        for i, ch in enumerate(reversed(p)):
            if i < len(s):
                if ch == '*' or ch == s[i]:
                    continue
                elif s[i] == '*':
                    s[i] = ch
                else:
                    s = ['*']
                    has_match = False
                    break
            else:
                s.append(ch)
    # assert s[-1] == '*'
    # assert all([x != '*' for x in s[:-1]])
    return s

T = int(input())
for t in range(T):
    N = int(input())
    patterns = []
    for i in range(N):
        patterns.append(input())
    s = find_match(patterns)
    s = ''.join(s)[::-1]
    if len(s) > 1:
        s = s[1:]
    print("Case #{}: {}".format(t + 1, s))