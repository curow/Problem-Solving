n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.sort()
median = a[n // 2]
print("median: {}".format(median))
print("cost: {}".format(sum([abs(x - median) for x in a])))
