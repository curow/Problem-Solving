S = int(1e9)
T = int(input())
mapping = {'N': (0, -1), 'S': (0, 1), 'W': (-1, 0), 'E': (1, 0)}
def decode(code):
    # print(code)
    import string
    if not code:
        return 0, 0
    if code[0] in string.digits:
        unbalance = 1
        count = 0
        for i, x in enumerate(code[2:]):
            if x == '(':
                unbalance += 1
            elif x == ')':
                unbalance -= 1
            if unbalance == 0:
                count = i
                break
        w1, h1 = decode(code[2:count + 2])
        w2, h2 = decode(code[count + 3:])
        d = int(code[0])
        w = (d * w1 + w2) % S
        h = (d * h1 + h2) % S
        return w, h
    elif code[0] in 'NSWE':
        count = -1
        for i, x in enumerate(code[1:]):
            if x not in 'NSWE':
                count = i
                break
        if count == -1:
            count = len(code) - 1
        w, h = 0, 0
        for ch in code[:count + 1]:
            dw, dh = mapping[ch]
            w = (w + dw) % S
            h = (h + dh) % S
        nw, nh = decode(code[count + 1:])
        w = (w + nw) % S
        h = (h + nh) % S
        return w, h
        # return code[:count + 1] + decode(code[count + 1:])
    else:
        raise RuntimeError

for t in range(1, T + 1):
    w, h = decode(input())
    print("Case #{}: {} {}".format(t, w + 1, h + 1))
