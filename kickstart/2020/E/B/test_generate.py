tests = []
for n in range(1, 6):
    for c in range(1, n + 1):
        for a in range(c, n + 1):
            for b in range(c, n + 1):
                tests.append((n, a, b, c))
print(len(tests))
for n, a, b, c in tests:
    print(n, a, b, c)
