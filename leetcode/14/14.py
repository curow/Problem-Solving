class Tree:
    def __init__(self, label):
        self.children = []
        self.label = label
        self.end_of_word = False

    def add(self, string):
        if not string:
            self.end_of_word = True
            return
        next_node = None
        for node in self.children:
            if node.label == string[0]:
                next_node = node
                break
        if not next_node:
            next_node = Tree(string[0])
            self.children.append(next_node)
        next_node.add(string[1:])
        
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        t = Tree("")
        for s in strs:
            if s == "":
                return ""
            t.add(s)
            if len(t.children) >= 2:
                return ""
        prefix = ""
        p = t
        while True:
            prefix += p.label
            if len(p.children) == 1 and not p.end_of_word:
                p = p.children[0]
            else:
                break
        return prefix
