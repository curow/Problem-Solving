from functools import lru_cache
class Solution:
    def checkValidString(self, s: str) -> bool:
        @lru_cache(maxsize=None)
        def search(k, debt):
            if k >= len(s):
                return debt == 0

            if s[k] == '(':
                debt += 1
                return search(k + 1, debt)
            elif s[k] == ')':
                if debt > 0:
                    debt -= 1
                    return search(k + 1, debt)
                else:
                    return False
            elif s[k] == '*':
                if search(k + 1, debt):
                    return True
                if search(k + 1, debt + 1):
                    return True
                if debt > 0 and search(k + 1, debt - 1):
                    return True
                return False
        return search(0, 0)
