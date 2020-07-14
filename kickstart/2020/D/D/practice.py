T = int(input())
for t in range(1, T + 1):
    n, q = [int(s) for s in input().split(" ")]
    v = [float('inf')] + [int(s) for s in input().split(" ")] + [float('inf')]
    answers = []
    for i in range(q):
        s, k = [int(s) for s in input().split(" ")]
        left_door, right_door = v[s - 1], v[s]
        cur_room, left_room, right_room = s, s - 1, s + 1
        for _ in range(k - 1):
            if left_door < right_door:
                cur_room = left_room
                left_room = left_room - 1
                left_door = v[cur_room - 1]
            else:
                cur_room = right_room
                right_room = right_room + 1
                right_door = v[cur_room]
        answers.append(cur_room)
    answer_string = ""
    for x in answers:
        answer_string += str(x) + " "
    print("Case #{}: {}".format(t, answer_string.strip()))
