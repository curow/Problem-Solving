def longest(s):
    best = count = 1
    prev = ''
    for x in s:
        if prev == x:
            count += 1
            best = max(best, count)
        else:
            count = 1
            prev = x
    return best

print(longest(input()))

