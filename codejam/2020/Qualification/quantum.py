def reverse(bits):
    return list(reversed(bits))

def complement(bits):
    return [1 - x for x in bits]

T, B = list(map(int, input().split()))
for _ in range(1, T + 1):
    if B == 10:
        prev = []
        indices = [i for i in range(1, 11)]
        for i in indices:
            print(i)
            bit = int(input())
            prev.append(bit)
    elif B == 20:
        print(1)
        prev_1 = int(input())
        prev_2_10 = []
        indices = [i for i in range(2, 11)]
        for i in indices:
            print(i)
            bit = int(input())
            prev_2_10.append(bit)
        prev_12_20 = []
        indices = [i for i in range(12, 21)]
        for i in indices:
            print(i)
            bit = int(input())
            prev_12_20.append(bit)

        print(11)
        current_11 = int(input())
        current_2_10 = []
        indices = [i for i in range(2, 11)]
        for i in indices:
            print(i)
            bit = int(input())
            current_2_10.append(bit)
        current_12_20 = []
        indices = [i for i in range(12, 21)]
        for i in indices:
            print(i)
            bit = int(input())
            current_12_20.append(bit)
        if prev_2_10 == current_2_10 and prev_12_20 == current_12_20:
            current_1 = prev_1
        else:
            prev_2_9 = prev_2_10[:-1]
            prev_12_19 = prev_12_20[:-1]
            current_2_9 = current_2_10[:-1]
            current_12_19 = current_12_20[:-1]
            if reverse(prev_2_9) == current_12_19 \
                and reverse(prev_12_19) == current_2_9:
                current_1 = prev_12_20[-1]
            elif complement(prev_12_20) == current_12_20 \
                and complement(prev_2_10) == current_2_10:
                current_1 = 1 - prev_1
            else:
                current_1 = 1 - prev_12_20[-1]
        prev = []
        prev.append(current_1)
        prev.extend(current_2_10)
        prev.append(current_11)
        prev.extend(current_12_20)
        assert len(prev) == 20, "total:{}\n1:{}\n2-10:{}\n11:{}\n12-20:{}".format(len(prev), current_1, current_2_10, current_11, current_12_20)
    else:
        prev = []
        for i in range(B - 10 + 1):
            indices = [j + i for j in range(1, 11)]
            current = []
            for j in indices:
                print(j)
                bit = int(input())
                current.append(bit)
            if prev:
                prev_last_nine = prev[-9:]
                current_first_nine = current[:9]
                if prev_last_nine == current_first_nine:
                    pass
                elif reverse(prev_last_nine) == current_first_nine:
                    prev = reverse(prev)
                elif complement(prev_last_nine) == current_first_nine:
                    prev = complement(prev)
                else:
                    prev = reverse(complement(prev))
                prev.append(current[-1])
            else:
                prev = current
    output = ''
    for bit in prev:
        output += str(bit)
    print(output)
    judge = input()
    if judge == 'N':
        break