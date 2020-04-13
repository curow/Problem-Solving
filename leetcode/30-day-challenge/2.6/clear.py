class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        balances = {}
        count = 0
        balances[count] = -1
        best = 0
        for i, num in enumerate(nums):
            if num == 0:
                count -= 1
            else:
                count += 1
            if count not in balances:
                balances[count] = i
            else:
                best = max(best, i - balances[count])
        return best
