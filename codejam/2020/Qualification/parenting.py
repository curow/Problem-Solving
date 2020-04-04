MINUTES = 24 * 60 + 1
INDEX = MINUTES

class Union:
    def __init__(self, N):
        self.array = [-1 for _ in range(N)]
    
    def size(self, v):
        root = self.find(v)
        return -self.array[root]

    def parent(self, v):
        return self.array[v]

    def find(self, v):
        p = self.parent(v)
        if p < 0:
            return v
        else:
            root = self.find(p)
            self.array[v] = root
            return root
        
    def union(self, v1, v2):
        root1 = self.find(v1)
        root2 = self.find(v2)
        if root1 == root2:
            return
        size1 = self.size(root1)
        size2 = self.size(root2)
        if size1 > size2:
            self.array[root1] += self.array[root2]
            self.array[root2] = root1
        else:
            self.array[root2] += self.array[root1]
            self.array[root1] = root2

T = int(input())
for _ in range(1, T + 1):
    C_set = Union(MINUTES + 1)
    J_set = Union(MINUTES + 1)
    N = int(input())
    result = ''
    done = False
    for __ in range(N):
        start, end = list(map(int, input().split()))
        if done:
            continue
        overlap_with_C = False
        overlap_with_J = False
        C_root = C_set.find(INDEX)
        J_root = J_set.find(INDEX)
        for minute in range(start, end):
            if C_set.find(minute) == C_root:
                overlap_with_C = True
                if overlap_with_J:
                    break
            if J_set.find(minute) == J_root:
                overlap_with_J = True
                if overlap_with_C:
                    break
        if overlap_with_C and overlap_with_J:
            result = 'IMPOSSIBLE'
            done = True
        elif overlap_with_C:
            result += 'J'
            for minute in range(start, end):
                J_set.union(minute, INDEX)
        else:
            result += 'C'
            for minute in range(start, end):
                C_set.union(minute, INDEX)
    print("Case #{}: {}".format(_, result))

