class Solution:
    def checkValidString(self, s: str) -> bool:
        lo, hi = 0, 0
        for x in s:
            if x == '(':
                lo += 1
                hi += 1
            elif x == ')':
                lo -= 1
                hi -= 1
            else:
                lo -= 1
                hi += 1
            if hi < 0:
                break
            lo = max(0, lo)
        return lo == 0
