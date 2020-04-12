def turn(array):
    count = 0
    prev = array[0]
    for x in array[1:]:
        if x < prev:
            count += prev - x
        else:
            prev = x
    return count

N = int(input())
array = list(map(int, input().split()))
print(turn(array))

