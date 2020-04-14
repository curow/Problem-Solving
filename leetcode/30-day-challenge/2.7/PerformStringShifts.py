class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        right_shift = 0
        for direction, amount in shift:
            right_shift += amount if direction == 1 else -amount
        if right_shift == 0:
            return s
        elif right_shift > 0:
            amount = right_shift % len(s)
            right = s[:-amount]
            left = s[-amount:]
        else:
            left_shift = - right_shift
            amount = left_shift % len(s)
            right = s[:amount]
            left = s[amount:]
        return left + right
