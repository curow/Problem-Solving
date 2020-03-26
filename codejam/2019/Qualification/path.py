class Node:
    def __init__(self, is_end=False):
        self.E = None
        self.S = None
        self.is_end = is_end

class Graph:
    def __init__(self, N, invaid_path):
        # build graph
        self.source = Node()
        current_layer = [self.source]
        for i in range(2, N + 1):
            next_layer = [Node() for _ in range(i)]
            for j, node in enumerate(current_layer):
                node.S = next_layer[j]
                node.E = next_layer[j + 1]
            current_layer = next_layer
        for i in range(N - 1, 0, -1):
            next_layer = [Node() for _ in range(i)]
            for j, node in enumerate(current_layer):
                if j - 1 >= 0:
                    node.S = next_layer[j - 1]
                if j < len(next_layer):
                    node.E = next_layer[j]
            current_layer = next_layer

        current_layer[0].is_end = True

        # remove invaid edges
        p = self.source
        prev = None
        for ch in invaid_path:
            prev = p
            if ch == 'E':
                p = p.E
                prev.E = None
            else:
                p = p.S
                prev.S = None
    
def dfs(node):
    if node is None:
        return False, ''
    elif node.is_end:
        return True, ''
    else:
        find, path = dfs(node.E)
        if find:
            return True, 'E' + path
        find, path = dfs(node.S)
        if find:
            return True, 'S' + path
        return False, ''

def iter_dfs(source):
    stack = []
    stack.append(('', source))
    while stack:
        path, node = stack.pop()
        if node.is_end:
            return path
        if node.E:
            stack.append((path + 'E', node.E))
        if node.S:
            stack.append((path + 'S', node.S))

T = int(input())
for i in range(1, T + 1):
    N = int(input())
    invaid_path = input()
    graph = Graph(N, invaid_path)
    print("Case #{}: {}".format(i, iter_dfs(graph.source)))
