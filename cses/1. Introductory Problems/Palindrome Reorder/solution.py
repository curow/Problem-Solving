s = input()
n = len(s)
d = {}
for c in s:
    if c in d:
        d[c] += 1
    else:
        d[c] = 1

valid = True
odd_cnt = 0
odd_val = ''
for c, v in d.items():
    if v % 2 == 1:
        odd_cnt += 1
        odd_val = c
        if n % 2 == 0 or odd_cnt == 2:
            valid = False
            break
if not valid:
    print("NO SOLUTION")
else:
    res = ''
    for c, v in d.items():
        res += c * (v // 2)
    temp = res[::-1]
    res += odd_val
    res += temp
    print(res)
