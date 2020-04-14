class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        left_shift = 0
        for direction, amount in shift:
            left_shift += amount if direction == 0 else -amount
        amount = left_shift % len(s)
        left = s[amount:]
        right = s[:amount]
        return left + right
