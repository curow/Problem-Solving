def get_char_list_input():
    return list(input())

def get_int_input():
    return int(input())

class ListNode:
    def __init__(self, char, left=None, right=None):
        self.char = char;
        self.left = left
        self.right = right

    def is_occupied(self):
        return self.left and self.right

    def has_neighbor(self, node):
        return self.left == node or self.right == node

    def rotate(self):
        self.left, self.right = self.right, self.left
        if self.left:
            self.left.rotate()
        if self.right:
            self.right.rotate()

    def get_all_linked_char(self, search_left=False, search_right=False):
        linked_lst = [self.char]
        if (self.left == None or not search_left) \
            and (self.right == None or not search_right):
            return linked_lst
        if self.left and search_left:
            linked_lst = self.left.get_all_linked_char(search_left=True) + linked_lst
        if self.right and search_right:
            linked_lst = linked_lst + self.right.get_all_linked_char(search_right=True)
        return linked_lst

    def has_loop(self):
        p = self.right
        while (p is not self and p):
            p = p.right
        if p is self:
            return True
        else:
            return False


def check_password(char_list):
    char_dict = {char : ListNode(char) for char in char_list}
    for char1, char2 in zip(char_list, char_list[1:]):
        node1, node2 = char_dict[char1], char_dict[char2]
        if node1.has_neighbor(node2):
            continue
        elif node1.is_occupied() or node2.is_occupied():
            return False, None
        elif node1.right == None and node2.left == None:
            node1.right = node2
            node2.left = node1
        elif node1.right == None and node2.right == None:
            node2.rotate()
            node1.right = node2
            node2.left = node1
        elif node1.left == None and node2.right == None:
            node2.right = node1
            node1.left = node2
        else:
            node1.rotate()
            node1.right = node2
            node2.left = node1
    import string
    solution = ""
    s = set(string.ascii_lowercase)
    for char in char_dict:
        if char_dict[char].has_loop():
            return False, None
        if char in s:
            linked_lst = char_dict[char].get_all_linked_char(search_left=True, search_right=True)
            solution += "".join(linked_lst)
            s -= set(linked_lst)
    solution += "".join(s)
    return True, solution
    


def main():
    n = get_int_input()
    # print(n)
    for _ in range(n):
        char_list = get_char_list_input()
        # print(char_list)
        ok, solution = check_password(char_list)
        if ok:
            print("YES")
            print(solution)
        else:
            print("NO")

    # print('test:')
    # a = ListNode('a')
    # b = a.right = ListNode('b', left=a)
    # c = b.right = ListNode('c', left=b)
    # print(b.get_all_linked_char(search_left=True, search_right=True))

main()
