class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        balances = {}
        balances[0] = -1
        best = count = 0
        for i, num in enumerate(nums):
            count += 1 if num == 1 else -1
            if count not in balances:
                balances[count] = i
            else:
                best = max(best, i - balances[count])
        return best
