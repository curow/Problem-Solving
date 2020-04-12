n = int(input())
one_missing = set(map(int, input().split()))
all_numbers = set(range(1, n + 1))
print((all_numbers - one_missing).pop())

