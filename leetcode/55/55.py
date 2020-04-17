class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last = len(nums) - 1
        hi = 0
        for i, num in enumerate(nums):
            if i <= hi:
                hi = max(hi, i + num)
                if hi >= last:
                    return True
            else:
                return False

